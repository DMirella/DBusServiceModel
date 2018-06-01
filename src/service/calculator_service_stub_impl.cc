#include "calculator_service_stub_impl.h"

#include "calculator_service_tasks.h"

namespace DBusServiceModel {
CalculatorServiceStubImpl::CalculatorServiceStubImpl(const std::shared_ptr<TaskSynchronicalQueue>& task_synchronical_queue) 
  : task_synchronical_queue_(task_synchronical_queue) {
}
void CalculatorServiceStubImpl::sum(const std::shared_ptr<CommonAPI::ClientId> _client, 
    				    int32_t _valueA, int32_t _valueB, sumReply_t _reply) {
  task_synchronical_queue_->Push(std::make_shared<TaskSum>(_valueA, _valueB, _reply));
}

void CalculatorServiceStubImpl::deduct(const std::shared_ptr<CommonAPI::ClientId> _client, 
    				       int32_t _valueA, int32_t _valueB, deductReply_t _reply) {
  task_synchronical_queue_->Push(std::make_shared<TaskDeduct>(_valueA, _valueB, _reply));
}

void CalculatorServiceStubImpl::multiply(const std::shared_ptr<CommonAPI::ClientId> _client, 
    					 int32_t _valueA, int32_t _valueB, multiplyReply_t _reply) {
  task_synchronical_queue_->Push(std::make_shared<TaskMultiply>(_valueA, _valueB, _reply));
}

void CalculatorServiceStubImpl::divide(const std::shared_ptr<CommonAPI::ClientId> _client, 
    				       int32_t _valueA, int32_t _valueB, divideReply_t _reply) {
  task_synchronical_queue_->Push(std::make_shared<TaskDivide>(_valueA, _valueB, _reply));
}
}  // namespace DBusServiceModel
