#ifndef DBUSSERVICEMODEL_SRC_CLIENT_CLIENT_CALCULATOR_DBUS_SERVICE_H_
#define DBUSSERVICEMODEL_SRC_CLIENT_CLIENT_CALCULATOR_DBUS_SERVICE_H_

#include <functional>
#include <memory>
#include <string>

#include "CommonAPI/CommonAPI.hpp"

#include "v1/com/luxoft/calculatorservice/CalculatorServiceProxy.hpp"

namespace DBusServiceModel {
class ClientCalculatorDBusService {
 public:
  ClientCalculatorDBusService() = delete;
  ClientCalculatorDBusService(const ClientCalculatorDBusService& service) = delete;
  ClientCalculatorDBusService(ClientCalculatorDBusService&& service) = delete;
  ClientCalculatorDBusService& operator=(const ClientCalculatorDBusService& service) = delete;
  ClientCalculatorDBusService& operator=(ClientCalculatorDBusService&& service) = delete;

  explicit ClientCalculatorDBusService(const std::string& service_name);
  ~ClientCalculatorDBusService() {}

  bool WaitAvailable();
  void SumAsync(int value_a, int value_b, const std::function<void(int)>& on_answer_function) const;
  void DivideAsync(int value_a, int value_b, const std::function<void(int)>& on_answer_function) const;
  void DeductAsync(int value_a, int value_b, const std::function<void(int)>& on_answer_function) const;
  void MultiplyAsync(int value_a, int value_b, const std::function<void(int)>& on_answer_function) const;
 private:
  bool Initialization();
  void OnRecieveServiceIntAnswer(int answer, const std::function<void(int)>& on_answer_function, 
			         const CommonAPI::CallStatus& status) const;

  bool is_client_ready_;
  std::string service_name_;
  std::shared_ptr<v1::com::luxoft::calculatorservice::CalculatorServiceProxy<>> service_proxy_;
  std::shared_ptr<CommonAPI::Runtime> runtime_;
};
}  // namespace DBusServiceModel

#endif  // DBUSSERVICEMODEL_SRC_CLIENT_CLIENT_CALCULATOR_DBUS_SERVICE_H_
