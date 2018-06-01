#include "calculator_service_stub_impl.h"
#include "calculator_service_tasks.h"

void CalculatorServiceStubImpl::CalculatorServiceStubImpl::sum(const std::shared_ptr<CommonAPI::ClientId> _client, 
    				    int32_t _valueA, int32_t _valueB, sumReply_t _reply) {
  task_manager_.addTaskToQueue(std::make_shared<CalculatorServiceTask::TaskSum>(_valueA, _valueB, _reply));
}

void CalculatorServiceStubImpl::CalculatorServiceStubImpl::deduct(const std::shared_ptr<CommonAPI::ClientId> _client, 
    				       int32_t _valueA, int32_t _valueB, deductReply_t _reply) {
  task_manager_.addTaskToQueue(std::make_shared<CalculatorServiceTask::TaskDeduct>(_valueA, _valueB, _reply));
}

void CalculatorServiceStubImpl::CalculatorServiceStubImpl::multiply(const std::shared_ptr<CommonAPI::ClientId> _client, 
    					 int32_t _valueA, int32_t _valueB, multiplyReply_t _reply) {
  task_manager_.addTaskToQueue(std::make_shared<CalculatorServiceTask::TaskMultiply>(_valueA, _valueB, _reply));
}

void CalculatorServiceStubImpl::CalculatorServiceStubImpl::divide(const std::shared_ptr<CommonAPI::ClientId> _client, 
    				       int32_t _valueA, int32_t _valueB, divideReply_t _reply) {
  task_manager_.addTaskToQueue(std::make_shared<CalculatorServiceTask::TaskDivide>(_valueA, _valueB, _reply));
}

