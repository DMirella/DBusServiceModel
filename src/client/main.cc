#include <ctime>
#include <iostream>
#include <unistd.h>
#include "client_calculator_dbus_service.h"


void onSumResultRecieved(const int answer){
  std::cout << "Answer for sum: " << answer << std::endl;
}
void onMulResultRecieved(const int answer){
  std::cout << "Answer for mul: " << answer << std::endl;
}
void onDivResultRecieved(const int answer){
  std::cout << "Answer for divide: " << answer << std::endl;
}
void onDedResultRecieved(const int answer){
  std::cout << "Answer for deduct: " << answer << std::endl;
}

int main(){
  srand(time(0));

  ClientCalculatorDBusService::ClientCalculatorDBusService service("CalculatorService");
  std::cout << "Client has created. Wait for service...\n";
  service.makeConnection();
  std::cout << "Service was found. Starting query cycle.\n";
	
  int cnt = 0;
  while(1){
    cnt++;
    switch(rand() % 4) {
    case 0:
      service.sumAsync(6, 2, onSumResultRecieved);
      break;
    case 1:
      service.deductAsync(6, 2, onDedResultRecieved);
      break;
    case 2:
      service.multiplyAsync(6, 2, onMulResultRecieved);
      break;
    case 3:
      service.divideAsync(6, 2, onDivResultRecieved);
      break;
    }
    std::cout << "Service call #" << cnt << std::endl;
    usleep(100000);
  }
  return 0;
}
