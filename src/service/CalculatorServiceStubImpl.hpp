#ifndef CALCULATOR_SERVICE_STUB_IMPL_HPP_
#define CALCULATOR_SERVICE_STUB_IMPL_HPP_

#include "TaskManager.hpp"
#include <v1/com/luxoft/calculatorservice/CalculatorServiceStubDefault.hpp>


class CalculatorServiceStubImpl
    : public v1::com::luxoft::calculatorservice::CalculatorServiceStubDefault {
 public:
  CalculatorServiceStubImpl() {}
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
  TaskManager task_manager_;
};

#endif  // CALCULATOR_SERVICE_STUB_IMPL_HPP_
