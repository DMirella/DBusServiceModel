#ifndef DBUSCLIENTCALCULATORSERVICE_H_
#define DBUSCLIENTCALCULATORSERVICE_H_

#include <unistd.h>
#include <thread>
#include <CommonAPI/CommonAPI.hpp>
#include <string>
#include <functional>
#include <v1/com/luxoft/calculatorservice/CalculatorServiceProxy.hpp>

class DBusCalculatorServiceClient{
 public:
  DBusCalculatorServiceClient(std::string service_name) : service_name_(std::move(service_name)) {
    runtime_ = CommonAPI::Runtime::get();
    service_proxy_ = runtime_->buildProxy<v1::com::luxoft::calculatorservice::CalculatorServiceProxy>("", service_name_);
  }

  void makeConnection() {
    while(!service_proxy_->isAvailable())std::this_thread::sleep_for(std::chrono::seconds(5));
  }

  void getSumAsync(const int& value_a, const int& value_b, std::function<void(const int&)> on_answer_function) const {
    service_proxy_->sumAsync(value_a, value_b, 
    [&on_answer_function](CommonAPI::CallStatus callstatus, const int &out) {
      on_answer_function(out);
    });
  }
  void getDivideAsync(const int& value_a, const int& value_b, std::function<void(const int&)> on_answer_function) const {
    service_proxy_->divideAsync(value_a, value_b, 
    [&on_answer_function](CommonAPI::CallStatus callstatus, const int &out) {
      on_answer_function(out);
    });
  }
  void getDeductAsync(const int& value_a, const int& value_b, std::function<void(const int&)> on_answer_function) const {
    service_proxy_->deductAsync(value_a, value_b, 
    [&on_answer_function](CommonAPI::CallStatus callstatus, const int &out) {
      on_answer_function(out);
    });
  }
  void getMultiplyAsync(const int& value_a, const int& value_b, std::function<void(const int&)> on_answer_function) const {
    service_proxy_->multiplyAsync(value_a, value_b, 
    [&on_answer_function](CommonAPI::CallStatus callstatus, const int &out) {
      on_answer_function(out);
    });
  }

 private:

  std::string service_name_;

  std::shared_ptr<CommonAPI::Runtime> runtime_;
  std::shared_ptr<v1::com::luxoft::calculatorservice::CalculatorServiceProxy<>> service_proxy_;
};


#endif  //DBUSCLIENTCALCULATORSERVICE_H_
