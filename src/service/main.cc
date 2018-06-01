#include <iostream>
#include <unistd.h>
#include "dbus_calculator_service.h"

int main() {
  DBusCalculatorService::DBusCalculatorService calculator_service("CalculatorService");
  calculator_service.startService();

  return 0;
}
