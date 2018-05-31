#include "dbus_calculator_service.h"
#include <iostream>

const size_t DBusCalculatorService::kDefualtSleepSeconds = 5;

void DBusCalculatorService::doServiceThread() { 
  std::cout << "Calculator service was started.\n";
  while(true) { 
    std::this_thread::sleep_for(std::chrono::seconds(kDefualtSleepSeconds)); 
  } 
}
