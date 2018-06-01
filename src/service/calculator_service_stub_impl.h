#ifndef DBUSSERVICEMODEL_SRC_SERVICE_CALCULATOR_SERVICE_STUB_IMPL_H_
#define DBUSSERVICEMODEL_SRC_SERVICE_CALCULATOR_SERVICE_STUB_IMPL_H_

#include <memory>
#include "CommonAPI/CommonAPI.hpp"
#include "task_synchronical_queue.h"
#include "v1/com/luxoft/calculatorservice/CalculatorServiceStubDefault.hpp"

namespace DBusServiceModel {
class CalculatorServiceStubImpl
    : public v1::com::luxoft::calculatorservice::CalculatorServiceStubDefault{
 public:
  CalculatorServiceStubImpl(const std::shared_ptr<TaskSynchronicalQueue>& task_synchronical_queue);
  CalculatorServiceStubImpl() = delete;
  CalculatorServiceStubImpl(const CalculatorServiceStubImpl& service_stub) = delete;
  CalculatorServiceStubImpl(CalculatorServiceStubImpl&& service_stub)      = delete;
  CalculatorServiceStubImpl& operator=(const CalculatorServiceStubImpl& calculator_service_stub_impl) = delete;
  CalculatorServiceStubImpl& operator=(CalculatorServiceStubImpl&& calculator_service_stub_impl)      = delete;
  virtual ~CalculatorServiceStubImpl() {}

  virtual void sum(const std::shared_ptr<CommonAPI::ClientId> _client, 
      		   int32_t _valueA, int32_t _valueB, sumReply_t _reply) override;
  virtual void deduct(const std::shared_ptr<CommonAPI::ClientId> _client, 
      		      int32_t _valueA, int32_t _valueB, deductReply_t _reply) override;
  virtual void multiply(const std::shared_ptr<CommonAPI::ClientId> _client, 
      			int32_t _valueA, int32_t _valueB, multiplyReply_t _reply) override;
  virtual void divide(const std::shared_ptr<CommonAPI::ClientId> _client, 
      		      int32_t _valueA, int32_t _valueB, divideReply_t _reply) override;
 private:
  std::shared_ptr<TaskSynchronicalQueue> task_synchronical_queue_;
};
}  // namespace DBusServiceModel

#endif  // DBUSSERVICEMODEL_SRC_SERVICE_CALCULATOR_SERVICE_STUB_IMPL_H_
