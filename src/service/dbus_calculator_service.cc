#include "dbus_calculator_service.h"

#include <iostream>

#include "calculator_service_stub_impl.h"
#include "task_solver.h"

namespace DBusServiceModel {
DBusCalculatorService::DBusCalculatorService(const std::string& name)
  : name_(name), runtime_(nullptr), service_(nullptr) {
  if (!(is_service_ready_ = Initialization())) {
     std::cerr << "Initialization failed!\n";
  }
}

DBusCalculatorService::~DBusCalculatorService() {
  task_synchronical_queue_.Destroy();
}

void DBusCalculatorService::AddTaskSolver() {
  if (is_service_ready_) {
    task_solvers_.emplace_back(std::make_unique<TaskSolver>(&task_synchronical_queue_));
  } else {
    std::cerr << "Error call DBusCalculatorService::AddTaskSolver(): service not ready.\n";
  }
}

bool DBusCalculatorService::Initialization() {
  runtime_ = CommonAPI::Runtime::get();
  if (runtime_ == nullptr) {
    std::cerr << "Error in DBusCalculatorService::Initialization(): runtime_ == nullptr\n";
    return false;
  }
  service_ = std::make_shared<CalculatorServiceStubImpl>(&task_synchronical_queue_);
  if (service_ == nullptr) {
    std::cerr << "Error in DBusCalculatorService::Initialization(): service_ == nullptr\n";
    return false;
  }
  runtime_->registerService("", name_, service_);
  return true;
}
}  // namespace DBusServiceModel
