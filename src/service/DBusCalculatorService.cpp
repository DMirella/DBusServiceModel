#include "DBusCalculatorService.hpp"

#include <iostream>

const size_t DBusCalculatorService::DEFAULT_SLEEP_SECONDS = 5;

void DBusCalculatorService::doServiceThread() { 
  std::cout << "Calculator service was started.\n";
  while(true) { 
    std::this_thread::sleep_for(std::chrono::seconds(DEFAULT_SLEEP_SECONDS)); 
  } 
}
