/* This file demonstrate the capabilities of API, which I had created. */
#include "DBusCalculatorService.hpp"


int main() {
  std::shared_ptr<Service::Service> calculator_service 
    = std::make_shared<DBusCalculatorService>("CalculatorService");  
  calculator_service->startService();
  while(1) { }

  return 0;
}
