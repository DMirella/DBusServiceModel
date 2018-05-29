#ifndef CLIENT_CALCULATOR_DBUS_SERVICE_HPP_
#define CLIENT_CALCULATOR_DBUS_SERVICE_HPP_

#include <unistd.h>
#include <thread>
#include <CommonAPI/CommonAPI.hpp>
#include <string>
#include <functional>
#include <v1/com/luxoft/calculatorservice/CalculatorServiceProxy.hpp>


class ClientCalculatorDBusService {
 using CallInfoPtr = std::unique_ptr<CommonAPI::CallInfo>;
 public:
  ClientCalculatorDBusService(std::string service_name) : service_name_(std::move(service_name)) {
    runtime_ = CommonAPI::Runtime::get();
    service_proxy_ = runtime_->buildProxy<v1::com::luxoft::calculatorservice::CalculatorServiceProxy>("", service_name_);
  }

  void makeConnection() {
    while(!service_proxy_->isAvailable())std::this_thread::sleep_for(std::chrono::seconds(5));
  }

  void getSumAsync(const int& value_a, const int& value_b, std::function<void(const int&)> on_answer_function) const {
    CallInfoPtr callinfo = std::make_unique<CommonAPI::CallInfo>(DEFAULT_TIMEOUT_TIME);
    service_proxy_->sumAsync(value_a, value_b, 
    [on_answer_function](CommonAPI::CallStatus callstatus, const int &out) {
      on_answer_function(out);
    }, callinfo.get());
  }
  void getDivideAsync(const int& value_a, const int& value_b, std::function<void(const int&)> on_answer_function) const {
    CallInfoPtr callinfo = std::make_unique<CommonAPI::CallInfo>(DEFAULT_TIMEOUT_TIME);
    service_proxy_->divideAsync(value_a, value_b, 
    [on_answer_function](CommonAPI::CallStatus callstatus, const int &out) {
      on_answer_function(out);
    }, callinfo.get());
  }
  void getDeductAsync(const int& value_a, const int& value_b, std::function<void(const int&)> on_answer_function) const {
    CallInfoPtr callinfo = std::make_unique<CommonAPI::CallInfo>(DEFAULT_TIMEOUT_TIME);
    service_proxy_->deductAsync(value_a, value_b, 
    [on_answer_function](CommonAPI::CallStatus callstatus, const int &out) {
      on_answer_function(out);
    }, callinfo.get());
  }
  void getMultiplyAsync(const int& value_a, const int& value_b, std::function<void(const int&)> on_answer_function) const {
    CallInfoPtr callinfo = std::make_unique<CommonAPI::CallInfo>(DEFAULT_TIMEOUT_TIME);
    service_proxy_->multiplyAsync(value_a, value_b, 
    [on_answer_function](CommonAPI::CallStatus callstatus, const int &out) {
      on_answer_function(out);
    }, callinfo.get());
  }

 private:

  std::string service_name_;

  std::shared_ptr<CommonAPI::Runtime> runtime_;
  std::shared_ptr<v1::com::luxoft::calculatorservice::CalculatorServiceProxy<>> service_proxy_;
  
  const static size_t DEFAULT_TIMEOUT_TIME;
};

const size_t ClientCalculatorDBusService::DEFAULT_TIMEOUT_TIME = (1ll << 31) - 1;

 

#endif  // CLIENT_CALCULATOR_DBUS_SERVICE_HPP_
