#ifndef DBUS_CALCULATOR_SERVICE_HPP_
#define DBUS_CALCULATOR_SERVICE_HPP_

#include "DBusService.hpp"
#include "CalculatorServiceStubImpl.hpp"


class DBusCalculatorService : public DBusService<CalculatorServiceStubImpl> {
 public:
  DBusCalculatorService(std::string name) 
    : DBusService(std::move(name), std::make_shared<CalculatorServiceStubImpl>()) {
  }
 protected:
  virtual void doServiceThread() override;

 private:
  const static size_t DEFAULT_SLEEP_SECONDS;
};

#endif  // DBUS_CALCULATOR_SERVICE_HPP_
