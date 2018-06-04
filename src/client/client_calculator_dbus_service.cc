#include "client_calculator_dbus_service.h"

#include <chrono>
#include <iostream>
#include <thread>

namespace {
const int k5sec 		       = std::chrono::seconds(5).count();
const int k1000000sec 		       = std::chrono::seconds(1000000).count();
const auto kDefualtTimeoutTime         = k1000000sec;
const auto kMakeConnectionSleepForTime = k5sec;
int64_t last_reg_id_ 		       = 0;
const CommonAPI::CallInfo callinfo(kDefualtTimeoutTime);
}

namespace DBusServiceModel {
ClientCalculatorDBusService::ClientCalculatorDBusService(const std::string& service_name) 
  : service_name_(service_name) {
  runtime_ = CommonAPI::Runtime::get();
  if (runtime_ == nullptr) {
    std::cerr << "Error ClientCalculatorDBusService::ClientCalculatorDBusService(...): runtime_ == nullptr\n";
    return;
  }
  service_proxy_ = runtime_->buildProxy<v1::com::luxoft::calculatorservice::CalculatorServiceProxy>(
      std::to_string(last_reg_id_), 
      service_name_);
  ++last_reg_id_;
}

void ClientCalculatorDBusService::MakeConnection() {
  while (!service_proxy_->isAvailable()) {
    std::this_thread::sleep_for(std::chrono::seconds(kMakeConnectionSleepForTime));
  }
}

void ClientCalculatorDBusService::SumAsync(int value_a, int value_b, 
     					   const std::function<void(int)>& on_answer_function) const {
  service_proxy_->sumAsync(value_a, value_b, 
    			  [&on_answer_function](CommonAPI::CallStatus callstatus, int out) {
     	 		    on_answer_function(out);
  			  }, &callinfo);
}

void ClientCalculatorDBusService::DivideAsync(int value_a, int value_b, 
      					      const std::function<void(int)>& on_answer_function) const {
  service_proxy_->divideAsync(value_a, value_b, 
  			     [&on_answer_function](CommonAPI::CallStatus callstatus, int out) {
    			       on_answer_function(out);
  			     }, &callinfo);
}

void ClientCalculatorDBusService::DeductAsync(int value_a, int value_b, 
     					      const std::function<void(int)>& on_answer_function) const {
  service_proxy_->deductAsync(value_a, value_b, 
  			     [&on_answer_function](CommonAPI::CallStatus callstatus, int out) {
   			       on_answer_function(out);
  		 	     }, &callinfo);
}
  
void ClientCalculatorDBusService::MultiplyAsync(int value_a, int value_b, 
     						const std::function<void(int)>& on_answer_function) const {
  service_proxy_->multiplyAsync(value_a, value_b, 
  			       [&on_answer_function](CommonAPI::CallStatus callstatus, int out) {
    			         on_answer_function(out);
  			       }, &callinfo);
}
}  // namespace DBusServiceModel
