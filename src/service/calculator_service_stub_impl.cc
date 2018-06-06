#include "calculator_service_stub_impl.h"

#include <iostream>

#include "calculator_service_tasks.h"
#include "task_synchronical_queue.h"

namespace DBusServiceModel {
CalculatorServiceStubImpl::CalculatorServiceStubImpl(TaskSynchronicalQueue* task_synchronical_queue) 
  : task_synchronical_queue_(task_synchronical_queue) {
  if (task_synchronical_queue_ == nullptr) {
    std::cerr << "Error in CalculatorServiceStubImpl::CalculatorServiceStubImpl(...): task_synchronical_queue_ == nullptr\n";
  }
}

void CalculatorServiceStubImpl::sum(const std::shared_ptr<CommonAPI::ClientId> _client, 
    				    int32_t _valueA, int32_t _valueB, sumReply_t _reply) {
  if (task_synchronical_queue_ == nullptr) {
    std::cerr << "Error in CalculatorServiceStubImpl::sum(...): task_synchronical_queue_ == nullptr\n";
    return;
  }
  task_synchronical_queue_->AddTask(std::make_shared<TaskSum>(_valueA, _valueB, _reply));
}

void CalculatorServiceStubImpl::deduct(const std::shared_ptr<CommonAPI::ClientId> _client, 
    				       int32_t _valueA, int32_t _valueB, deductReply_t _reply) {
  if (task_synchronical_queue_ == nullptr) {
    std::cerr << "Error in CalculatorServiceStubImpl::deduct(...): task_synchronical_queue_ == nullptr\n";
    return;
  }
  task_synchronical_queue_->AddTask(std::make_shared<TaskDeduct>(_valueA, _valueB, _reply));
}

void CalculatorServiceStubImpl::multiply(const std::shared_ptr<CommonAPI::ClientId> _client, 
    					 int32_t _valueA, int32_t _valueB, multiplyReply_t _reply) {
  if (task_synchronical_queue_ == nullptr) {
    std::cerr << "Error in CalculatorServiceStubImpl::multiply(...): task_synchronical_queue_ == nullptr\n";
    return;
  }
  task_synchronical_queue_->AddTask(std::make_shared<TaskMultiply>(_valueA, _valueB, _reply));
}

void CalculatorServiceStubImpl::divide(const std::shared_ptr<CommonAPI::ClientId> _client, 
    				       int32_t _valueA, int32_t _valueB, divideReply_t _reply) {
  if (task_synchronical_queue_ == nullptr) {
    std::cerr << "Error in CalculatorServiceStubImpl::divide(...): task_synchronical_queue_ == nullptr\n";
    return;
  }
  task_synchronical_queue_->AddTask(std::make_shared<TaskDivide>(_valueA, _valueB, _reply));
}
}  // namespace DBusServiceModel
