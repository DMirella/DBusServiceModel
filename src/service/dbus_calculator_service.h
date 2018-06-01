#ifndef DBUSSERVICEMODEL_SRC_SERVICE_DBUS_CALCULATOR_SERVICE_H_
#define DBUSSERVICEMODEL_SRC_SERVICE_DBUS_CALCULATOR_SERVICE_H_

#include <CommonAPI/CommonAPI.hpp>
#include <memory>
#include <string>
#include <thread>
#include "calculator_service_stub_impl.h"

namespace {
const int _5sec = 5;
constexpr int kDefualtSleepSeconds = _5sec;
}

class DBusCalculatorService {
 public:
  explicit DBusCalculatorService(const std::string& name);
  ~DBusCalculatorService();
  void startService();
 private:
  std::string name_;
  std::shared_ptr<CalculatorServiceStubImpl> service_;
  std::shared_ptr<CommonAPI::Runtime> runtime_;  
  std::thread service_thread_;
};

#endif  // DBUSSERVICEMODEL_SRC_SERVICE_DBUS_CALCULATOR_SERVICE_H_
