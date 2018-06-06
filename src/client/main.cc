#include <unistd.h>

#include <ctime>
#include <iostream>
#include <string>

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
  const int kTimeoutTimeNs = 100000;
  const int kValueA = 6;
  const int kValueB = 2;

  DBusServiceModel::ClientCalculatorDBusService service(kServiceName);
  std::cout << "Client has created. Wait for service...\n";
  bool connect_result = false;
  for (int current_try = 0; current_try < kCountTryToConnectionService; ++current_try) {
    if (service.WaitAvailable()) {
      connect_result = true;
      break;
    }
  }
  if (!connect_result) {
    std::cerr << "Connection to service failed.\n";
    return 0;
  }
  std::cout << "Service was found. Starting query cycle.\n";
	
  int call_count = 1;
  while (true) {
    switch(rand() % 4) {
    case 0:
      service.SumAsync(kValueA, kValueB, onSumResultRecieved);
      break;
    case 1:
      service.DeductAsync(kValueA, kValueB, onDedResultRecieved);
      break;
    case 2:
      service.MultiplyAsync(kValueA, kValueB, onMulResultRecieved);
      break;
    case 3:
      service.DivideAsync(kValueA, kValueB, onDivResultRecieved);
      break;
    }
    std::cout << "Service call #" << call_count++ << std::endl;
    usleep(kTimeoutTimeNs);
  }
  return 0;
}
