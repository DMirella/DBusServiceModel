#include "ClientCalculatorDBusService.hpp"


const size_t ClientCalculatorDBusService::DEFAULT_TIMEOUT_TIME = (1ll << 31) - 1;
size_t ClientCalculatorDBusService::last_reg_id_ = 0;


ClientCalculatorDBusService::ClientCalculatorDBusService(std::string service_name) 
    : service_name_(std::move(service_name)) {
  runtime_ = CommonAPI::Runtime::get();
  service_proxy_ = runtime_->buildProxy<v1::com::luxoft::calculatorservice::CalculatorServiceProxy>(std::to_string(last_reg_id_), service_name_);
  ++last_reg_id_;
}

void ClientCalculatorDBusService::getSumAsync(const int& value_a, const int& value_b, std::function<void(const int&)> on_answer_function) const {
  CallInfoPtr callinfo = std::make_unique<CommonAPI::CallInfo>(DEFAULT_TIMEOUT_TIME);
  service_proxy_->sumAsync(value_a, value_b, 
  [on_answer_function](CommonAPI::CallStatus callstatus, const int &out) {
    on_answer_function(out);
  }, callinfo.get());
}

void ClientCalculatorDBusService::getDivideAsync(const int& value_a, const int& value_b, std::function<void(const int&)> on_answer_function) const {
  CallInfoPtr callinfo = std::make_unique<CommonAPI::CallInfo>(DEFAULT_TIMEOUT_TIME);
  service_proxy_->divideAsync(value_a, value_b, 
  [on_answer_function](CommonAPI::CallStatus callstatus, const int &out) {
    on_answer_function(out);
  }, callinfo.get());
}

void ClientCalculatorDBusService::getDeductAsync(const int& value_a, const int& value_b, std::function<void(const int&)> on_answer_function) const {
  CallInfoPtr callinfo = std::make_unique<CommonAPI::CallInfo>(DEFAULT_TIMEOUT_TIME);
  service_proxy_->deductAsync(value_a, value_b, 
  [on_answer_function](CommonAPI::CallStatus callstatus, const int &out) {
    on_answer_function(out);
  }, callinfo.get());
}
  
void ClientCalculatorDBusService::getMultiplyAsync(const int& value_a, const int& value_b, std::function<void(const int&)> on_answer_function) const {
  CallInfoPtr callinfo = std::make_unique<CommonAPI::CallInfo>(DEFAULT_TIMEOUT_TIME);
  service_proxy_->multiplyAsync(value_a, value_b, 
  [on_answer_function](CommonAPI::CallStatus callstatus, const int &out) {
    on_answer_function(out);
  }, callinfo.get());
}
