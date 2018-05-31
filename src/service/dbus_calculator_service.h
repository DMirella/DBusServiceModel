#ifndef DBUS_CALCULATOR_SERVICE_HPP_
#define DBUS_CALCULATOR_SERVICE_HPP_

#include "dbus_service.h"
#include "calculator_service_stub_impl.h"

class DBusCalculatorService 
    : public Service::DBusService::DBusService<CalculatorServiceStubImpl> {
 public:
  explicit DBusCalculatorService(std::string name) 
    : DBusService(std::move(name), std::make_shared<CalculatorServiceStubImpl>()) {
  }
 protected:
  virtual void doServiceThread() override;
 private:
  const static size_t kDefualtSleepSeconds;
};

#endif  // DBUS_CALCULATOR_SERVICE_HPP_
