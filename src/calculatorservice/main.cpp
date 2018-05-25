#include "DBusCalculatorService.hpp"

int main() {
  std::shared_ptr<Service> calculator_service = std::make_shared<DBusCalculatorService>("CalculatorService");
  calculator_service->startService();

  return 0;
}
