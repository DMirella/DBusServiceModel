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
  explicit ClientCalculatorDBusService(std::string service_name);
  inline void makeConnection() {
    while(!service_proxy_->isAvailable())
      std::this_thread::sleep_for(std::chrono::seconds(5));
  }

  void getSumAsync(const int& value_a, const int& value_b, 
                   std::function<void(const int&)> on_answer_function) const;
  void getDivideAsync(const int& value_a, const int& value_b, 
                   std::function<void(const int&)> on_answer_function) const;
  void getDeductAsync(const int& value_a, const int& value_b, 
                      std::function<void(const int&)> on_answer_function) const;
  void getMultiplyAsync(const int& value_a, const int& value_b, 
                        std::function<void(const int&)> on_answer_function) const;
 private:
  std::string service_name_;
  std::shared_ptr<CommonAPI::Runtime> runtime_;
  std::shared_ptr<v1::com::luxoft::calculatorservice::CalculatorServiceProxy<>> service_proxy_;
  const static int32_t kDefualtTimeoutTime;
  static int64_t last_reg_id_;
};

 

#endif  // CLIENT_CALCULATOR_DBUS_SERVICE_HPP_
