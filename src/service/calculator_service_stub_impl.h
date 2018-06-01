#ifndef DBUSSERVICEMODEL_SRC_SERVICE_CALCULATOR_SERVICE_STUB_IMPL_H_
#define DBUSSERVICEMODEL_SRC_SERVICE_CALCULATOR_SERVICE_STUB_IMPL_H_

#include <CommonAPI/CommonAPI.hpp>
#include <memory>
#include "task_consumer_producer_queue.h"
#include "v1/com/luxoft/calculatorservice/CalculatorServiceStubDefault.hpp"

namespace CalculatorServiceStubImpl {
class CalculatorServiceStubImpl
    : public v1::com::luxoft::calculatorservice::CalculatorServiceStubDefault{
 public:
  CalculatorServiceStubImpl() {}
  CalculatorServiceStubImpl(const CalculatorServiceStubImpl& service_stub) = delete;
  CalculatorServiceStubImpl(CalculatorServiceStubImpl&& service_stub)      = delete;
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
  TaskConsumerProducerQueue::TaskConsumerProducerQueue task_manager_;
};
}  // namespace CalculatorServiceStubImpl

#endif  // DBUSSERVICEMODEL_SRC_SERVICE_CALCULATOR_SERVICE_STUB_IMPL_H_
