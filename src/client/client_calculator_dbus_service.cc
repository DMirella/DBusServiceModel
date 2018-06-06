#include "client_calculator_dbus_service.h"

#include <chrono>
#include <iostream>
#include <thread>

namespace DBusServiceModel {
namespace {
const auto kDefaultTimeoutTime = std::chrono::seconds(10000000);
const auto kStartMakeConnectionSleepForTime = std::chrono::seconds(5);
const auto kZeroSeconds = std::chrono::seconds(0);
int64_t gLastRegId = 0;
const CommonAPI::CallInfo gCallinfo = CommonAPI::CallInfo(kDefaultTimeoutTime.count());
}

ClientCalculatorDBusService::ClientCalculatorDBusService(const std::string& service_name) 
    : service_name_(service_name), runtime_(nullptr), service_proxy_(nullptr), is_client_ready_(false) {
  if (!(is_client_ready_ = Initialization())) {
    std::cerr << "Initialization failed.\n";
  }
}

bool ClientCalculatorDBusService::WaitAvailable() {
  if (!is_client_ready_) {
    std::cerr << "Error in ClientCalculatorDBusService::WaitAvailable(): is_client_ready_ == false";
    return false;
  }
  std::cout << "Waiting for available service...\n";
  bool service_available = false;
  for (auto sleep_time = kStartMakeConnectionSleepForTime; sleep_time > kZeroSeconds; sleep_time /= 2) {
    if (service_proxy_->isAvailable()) {
      service_available = true;
      break;
    }
    std::cout << "Wait for " << sleep_time.count() << " seconds.\n";
    std::this_thread::sleep_for(sleep_time);
  }
  if (!service_available) {
    std::cout << "Service not available now.\n";
  }
  return service_available;
}

void ClientCalculatorDBusService::SumAsync(int value_a, int value_b, 
     					   const std::function<void(int)>& on_answer_function) const {
  if (service_proxy_ == nullptr || !is_client_ready_) {
    std::cerr << "Error in ClientCalculatorDBusService: client not ready to use or service_proxy_ == nullptr";
    return;
  }
  service_proxy_->sumAsync(value_a, value_b, 
    			  [this, &on_answer_function](const CommonAPI::CallStatus& callstatus, int out) {
    			    OnRecieveServiceIntAnswer(out, on_answer_function, callstatus);
  			  }, &gCallinfo);
}

void ClientCalculatorDBusService::DivideAsync(int value_a, int value_b, 
      					      const std::function<void(int)>& on_answer_function) const {
  if (service_proxy_ == nullptr || !is_client_ready_) {
    std::cerr << "Error in ClientCalculatorDBusService: client not ready to use or service_proxy_ == nullptr";
    return;
  }
  service_proxy_->divideAsync(value_a, value_b, 
  			     [this, &on_answer_function](const CommonAPI::CallStatus& callstatus, int out) {
    			       OnRecieveServiceIntAnswer(out, on_answer_function, callstatus);
  			     }, &gCallinfo);
}

void ClientCalculatorDBusService::DeductAsync(int value_a, int value_b, 
     					      const std::function<void(int)>& on_answer_function) const {
  if (service_proxy_ == nullptr || !is_client_ready_) {
    std::cerr << "Error in ClientCalculatorDBusService: client not ready to use or service_proxy_ == nullptr";
    return;
  }
  service_proxy_->deductAsync(value_a, value_b, 
  			     [this, &on_answer_function](const CommonAPI::CallStatus& callstatus, int out) {
    			       OnRecieveServiceIntAnswer(out, on_answer_function, callstatus);
  		 	     }, &gCallinfo);
}
  
void ClientCalculatorDBusService::MultiplyAsync(int value_a, int value_b, 
     						const std::function<void(int)>& on_answer_function) const {
  if (service_proxy_ == nullptr || !is_client_ready_) {
    std::cerr << "Error in ClientCalculatorDBusService: client not ready to use or service_proxy_ == nullptr";
    return;
  }
  service_proxy_->multiplyAsync(value_a, value_b, 
  			       [this, &on_answer_function](const CommonAPI::CallStatus& callstatus, int out) {
    			         OnRecieveServiceIntAnswer(out, on_answer_function, callstatus);
  			       }, &gCallinfo);
}

bool ClientCalculatorDBusService::Initialization() {
  runtime_ = CommonAPI::Runtime::get();
  if (runtime_ == nullptr) {
    std::cerr << "Error ClientCalculatorDBusService::Initialization(): runtime_ == nullptr\n";
    return false;
  }
  service_proxy_ = runtime_->buildProxy<v1::com::luxoft::calculatorservice::CalculatorServiceProxy>(
      std::to_string(gLastRegId), 
      service_name_);
  if (service_proxy_ == nullptr) {
    std::cerr << "Error ClientCalculatorDBusService::Initialization(): service_proxy_ == nullptr\n";
    return false;
  }
  ++gLastRegId;
  return true;
}

void ClientCalculatorDBusService::OnRecieveServiceIntAnswer(int answer, const std::function<void(int)>& on_answer_function,
							    const CommonAPI::CallStatus& callstatus) const {
  if (callstatus != CommonAPI::CallStatus::SUCCESS) {
    std::cerr << "Service call failed!\n";
    return;
  }
  on_answer_function(answer);
}
}  // namespace DBusServiceModel
