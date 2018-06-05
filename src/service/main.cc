#include <iostream>
#include <unistd.h>

#include "dbus_calculator_service.h"

int main() {
  const auto kMainTimeOut = 10000000;
  const std::string kServiceName = "CalculatorService";
  DBusServiceModel::DBusCalculatorService calculator_service(kServiceName);
  calculator_service.AddTaskSolver();
  std::cout << "Server was started, wait for clients...\n";

  usleep(kMainTimeOut);
  return 0;
}
