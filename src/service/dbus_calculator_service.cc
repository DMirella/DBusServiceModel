#include <iostream>
#include "dbus_calculator_service.h"

DBusCalculatorService::DBusCalculatorService(const std::string& name)
  : name_(name) {
  runtime_ = CommonAPI::Runtime::get();
  if(runtime_ == nullptr) {
    std::cerr << "Error in DBusCalculatorService::DBusCalculatorService(): runtime_ == nullptr\n";
    return;
  }
  service_ = std::make_shared<CalculatorServiceStubImpl>();
}

DBusCalculatorService::~DBusCalculatorService() {
  
}

void DBusCalculatorService::startService() {
  if(runtime_ == nullptr) {
    std::cerr << "Error in DBusCalculatorService::startService(): runtime_ == nullptr\n";
    return;
  }
  runtime_->registerService("", name_, service_);
  auto doServiceThreadFunc = []() {
			       std::cout << "Calculator service was started.\n";
  			       while (true) { 
    			         std::this_thread::sleep_for(std::chrono::seconds(kDefualtSleepSeconds));
			       }
                             };
  service_thread_ = std::thread(doServiceThreadFunc);
  if (service_thread_.joinable()) {
    service_thread_.join();
  }
}
