//will be edit int future

#include "DBusClientService.hpp"
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
	
	

  while(1){
  switch(rand())
    service.getSumAsync(6, 2, onSumResultRecieved);
     usleep(19000);
  }
  return 0;
}
