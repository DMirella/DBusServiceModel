#ifndef CALCULATORSERVICE_STUBIMPL_H_
#define CALCULATORSERVICE_STUBIMPL_H_

#include "TaskManager.hpp"
#include <v1/com/luxoft/calculatorservice/CalculatorServiceStubDefault.hpp>

class CalculatorServiceStubImpl : public v1::com::luxoft::calculatorservice::CalculatorServiceStubDefault {
 public:
  CalculatorServiceStubImpl() { }
  virtual ~CalculatorServiceStubImpl() { }
 
  virtual void sum(const std::shared_ptr<CommonAPI::ClientId> _client, int32_t _valueA, int32_t _valueB, sumReply_t _reply);
  virtual void deduct(const std::shared_ptr<CommonAPI::ClientId> _client, int32_t _valueA, int32_t _valueB, deductReply_t _reply);
  virtual void multiply(const std::shared_ptr<CommonAPI::ClientId> _client, int32_t _valueA, int32_t _valueB, multiplyReply_t _reply);
  virtual void divide(const std::shared_ptr<CommonAPI::ClientId> _client, int32_t _valueA, int32_t _valueB, divideReply_t _reply);

 private:
  TaskManager task_manager_;
};

#endif  //CALCULATORSERVICE_STUBIMPL_H_
