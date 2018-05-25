#ifndef DBUSCALCULATORSERVICE_H_
#define DBUSCALCULATORSERVICE_H_

#include "DBusService.hpp"
#include "CalculatorServiceStubImpl.hpp"

#include <iostream>


class DBusCalculatorService : public DBusService<CalculatorServiceStubImpl>{
 public:
  DBusCalculatorService(std::string name) 
    : DBusService(std::move(name), std::make_unique<CalculatorServiceStubImpl>()) {
  }
 protected:
  virtual void doServiceThread() override { 
    std::cout << "Calculator service was started.\n";
    while(true) { std::this_thread::sleep_for(std::chrono::seconds(5)); } 
  }
};

#endif  //DBUSCALCULATORSERVICE_H_
