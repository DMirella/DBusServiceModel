#ifndef DBUSCALCULATORSERVICE_H_
#define DBUSCALCULATORSERVICE_H_

#include "DBusService.hpp"
#include "CalculatorServiceStubImpl.hpp"


class DBusCalculatorService : public DBusService<CalculatorServiceStubImpl>{
 public:
  DBusCalculatorService(std::string name) 
    : DBusService(std::move(name), std::make_unique<CalculatorServiceStubImpl>()) {
  }
 protected:
  virtual void doServiceThread() override { }
};

#endif  //DBUSCALCULATORSERVICE_H_
