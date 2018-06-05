#include <ctime>
#include <iostream>
#include <string>
#include <unistd.h>

#include "client_calculator_dbus_service.h"

int gCountAnswers;

void onSumResultRecieved(int answer){
  std::cout << "Answer #" << ++gCountAnswers << " for sum: " << answer << std::endl;
}
void onMulResultRecieved(int answer){
  std::cout << "Answer #" << ++gCountAnswers << " for mul: " << answer << std::endl;
}
void onDivResultRecieved(int answer){
  std::cout << "Answer #" << ++gCountAnswers << " for divide: " << answer << std::endl;
}
void onDedResultRecieved(int answer){
  std::cout << "Answer #" << ++gCountAnswers << " for deduct: " << answer << std::endl;
}

int main(){
  srand(time(0));
  const std::string kServiceName = "CalculatorService";
  const int kCountTryToConnectionService = 5;

  DBusServiceModel::ClientCalculatorDBusService service(kServiceName);
  std::cout << "Client has created. Wait for service...\n";
  for (int current_try = kCountTryToConnectionService; current_try >= 0; --current_try) {
    if (service.WaitAvailable()) break;
  }
  if (!service.WaitAvailable()) {
    std::cerr << "Connection to service failed.\n";
    return 0;
  }
  std::cout << "Service was found. Starting query cycle.\n";
	
  int call_count = 1;
  while (true) {
    switch(rand() % 4) {
    case 0:
      service.SumAsync(6, 2, onSumResultRecieved);
      break;
    case 1:
      service.DeductAsync(6, 2, onDedResultRecieved);
      break;
    case 2:
      service.MultiplyAsync(6, 2, onMulResultRecieved);
      break;
    case 3:
      service.DivideAsync(6, 2, onDivResultRecieved);
      break;
    }
    std::cout << "Service call #" << call_count++ << std::endl;
    usleep(100000);
  }
  return 0;
}
