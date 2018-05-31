#ifndef DBUSSERVICEMODEL_SRC_CLIENT_CLIENT_CALCULATOR_DBUS_SERVICE_H_
#define DBUSSERVICEMODEL_SRC_CLIENT_CLIENT_CALCULATOR_DBUS_SERVICE_H_

#include <CommonAPI/CommonAPI.hpp>
#include <functional>
#include <string>
#include <thread>
#include <unistd.h>
#include "v1/com/luxoft/calculatorservice/CalculatorServiceProxy.hpp"

namespace {
const int _1000000sec = 1000000;
const int _5sec = 5;
constexpr int kDefualtTimeoutTime = _1000000sec;
int64_t last_reg_id_ = 0;
const CommonAPI::CallInfo callinfo(kDefualtTimeoutTime);
}

class ClientCalculatorDBusService {
 public:
  explicit ClientCalculatorDBusService(const std::string& service_name);

  void makeConnection();
  void sumAsync(const int value_a, const int value_b, 
                   std::function<void(int)> on_answer_function) const;
  void divideAsync(const int value_a, const int value_b, 
                   std::function<void(int)> on_answer_function) const;
  void deductAsync(const int value_a, const int value_b, 
                      std::function<void(int)> on_answer_function) const;
  void multiplyAsync(const int value_a, const int value_b, 
                        std::function<void(int)> on_answer_function) const;
 private:
  std::string service_name_;
  std::shared_ptr<CommonAPI::Runtime> runtime_;
  std::shared_ptr<v1::com::luxoft::calculatorservice::CalculatorServiceProxy<>> service_proxy_;
};

 

#endif  // DBUSSERVICEMODEL_SRC_CLIENT_CLIENT_CALCULATOR_DBUS_SERVICE_H_
