#include <iostream>
#include "dbus_calculator_service.h"


namespace {
const int _5sec = 5;
const int kDefualtSleepSeconds = _5sec;
const int kTaskSolverCount = 1;
}

namespace DBusServiceModel {
DBusCalculatorService::DBusCalculatorService(const std::string& name)
  : name_(name) {
  runtime_ = CommonAPI::Runtime::get();
  if (runtime_ == nullptr) {
    std::cerr << "Error in DBusCalculatorService::DBusCalculatorService(): runtime_ == nullptr\n";
    return;
  }
  task_synchronical_queue_ = std::make_shared<TaskSynchronicalQueue>();
  service_ = std::make_shared<CalculatorServiceStubImpl>(task_synchronical_queue_);
}

DBusCalculatorService::~DBusCalculatorService() {
  task_synchronical_queue_.reset();
}

void DBusCalculatorService::StartService() {
  if (runtime_ == nullptr) {
    std::cerr << "Error in DBusCalculatorService::startService(): runtime_ == nullptr\n";
    return;
  }
  runtime_->registerService("", name_, service_);
}

void DBusCalculatorService::AddTaskSolver() {
  task_solvers_.push_back(std::make_unique<TaskSolver>(task_synchronical_queue_));
}
}  // namespace DBusServiceModel
