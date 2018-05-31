#include <chrono>
#include <iostream>
#include "client_calculator_dbus_service.h"

ClientCalculatorDBusService::ClientCalculatorDBusService(const std::string& service_name) 
    : service_name_(service_name) {
  runtime_ = CommonAPI::Runtime::get();
  if (runtime_ == nullptr) {
    std::cerr << "Error ClientCalculatorDBusService::ClientCalculatorDBusService(...): runtime_ == nullptr\n";
    return;
  }
  service_proxy_ 
    = runtime_->buildProxy<v1::com::luxoft::calculatorservice::CalculatorServiceProxy>(std::to_string(last_reg_id_), service_name_);
  ++last_reg_id_;
}

void ClientCalculatorDBusService::makeConnection() {
  while (!service_proxy_->isAvailable()) {
    std::this_thread::sleep_for(std::chrono::seconds(_5sec));
  }
}

void ClientCalculatorDBusService::sumAsync(const int value_a, const int value_b, 
     					      std::function<void(int)> on_answer_function) const {
  service_proxy_->sumAsync(value_a, value_b, 
    			  [&on_answer_function](CommonAPI::CallStatus callstatus, int out) {
     	 		    on_answer_function(out);
  			  }, &callinfo);
}

void ClientCalculatorDBusService::divideAsync(const int value_a, const int value_b, 
      						 std::function<void(int)> on_answer_function) const {
  service_proxy_->divideAsync(value_a, value_b, 
  			     [&on_answer_function](CommonAPI::CallStatus callstatus, int out) {
    			       on_answer_function(out);
  			     }, &callinfo);
}

void ClientCalculatorDBusService::deductAsync(const int value_a, const int value_b, 
     						 std::function<void(int)> on_answer_function) const {
  service_proxy_->deductAsync(value_a, value_b, 
  			     [&on_answer_function](CommonAPI::CallStatus callstatus, int out) {
   			       on_answer_function(out);
  		 	     }, &callinfo);
}
  
void ClientCalculatorDBusService::multiplyAsync(const int value_a, const int value_b, 
     						   std::function<void(int)> on_answer_function) const {
  service_proxy_->multiplyAsync(value_a, value_b, 
  			       [&on_answer_function](CommonAPI::CallStatus callstatus, int out) {
    			         on_answer_function(out);
  			       }, &callinfo);
}
