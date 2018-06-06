#include <iostream>
#include <unistd.h>

#include "dbus_calculator_service.h"

int main() {
  const auto kMainTimeOutNs = 10000000;
  const std::string kServiceName = "CalculatorService";
  DBusServiceModel::DBusCalculatorService calculator_service(kServiceName);
  calculator_service.AddTaskSolver();
  std::cout << "Server was started, wait for clients...\n";

  usleep(kMainTimeOutNs);
  return 0;
}
