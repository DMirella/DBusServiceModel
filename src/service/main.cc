#include "dbus_calculator_service.h"
#include <iostream>
#include <unistd.h>

int main() {
//std::cout << "ok\n";
  DBusCalculatorService* ca = new  DBusCalculatorService("CalculatorService");
  ca->startService();
delete ca;
  //TaskConsumerProducerQueue q;
  //q.startSolveThread();

  return 0;
}
