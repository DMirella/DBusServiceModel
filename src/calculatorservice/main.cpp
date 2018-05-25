#include "DBusCalculatorService.hpp"

int main() {
  Service* calculator_service = new DBusCalculatorService("CalculatorService");
  //calculator_service->startService();

  return 0;
}
