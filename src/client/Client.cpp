//will be edit int future

#include "DBusClientService.hpp"
//#include "ClientService.hpp"
#include <iostream>
#include <vector>
#include <ctime>


void onSumResultRecieved(const int& answer){
  std::cout << "Answer for sum: " << answer << std::endl;
}

void onMulResultRecieved(const int& answer){
  std::cout << "Answer for mul: " << answer << std::endl;
}

void onDivResultRecieved(const int& answer){
  std::cout << "Answer for divide: " << answer << std::endl;
}

void onDedResultRecieved(const int& answer){
  std::cout << "Answer for deduct: " << answer << std::endl;
}

int main(){
  DBusCalculatorServiceClient service("CalculatorService");
  service.makeConnection();
	
	
  int cnt = 0;
  while(1){
    switch(rand() % 1){
     case 0:
       cnt++;
       service.getSumAsync(6, 2, onSumResultRecieved);
       break;
     /*case 1:
       service.getDeductAsync(6, 2, onDedResultRecieved);
       break;
     case 2:
       service.getDivideAsync(6, 2, onDivResultRecieved);
       break;
     case 3:
       service.getMultiplyAsync(6, 2, onMulResultRecieved);
       break;*/
    }
    std::cout << "Service call #" << cnt << std::endl;
    usleep(100000);
  }
  return 0;
}
