#include <iostream>
#include <unistd.h>

#include "dbus_calculator_service.h"

int main() {
  DBusServiceModel::DBusCalculatorService calculator_service("CalculatorService");
  calculator_service.StartService();
  calculator_service.AddTaskSolver();
  std::cout << "Server was started, wait for clients...\n";
  
  usleep(10000000);
  return 0;
}
