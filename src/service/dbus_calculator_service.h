#ifndef DBUSSERVICEMODEL_SRC_SERVICE_DBUS_CALCULATOR_SERVICE_H_
#define DBUSSERVICEMODEL_SRC_SERVICE_DBUS_CALCULATOR_SERVICE_H_

#include <list>
#include <memory>
#include <string>

#include "CommonAPI/CommonAPI.hpp"

#include "task_synchronical_queue.h"

namespace DBusServiceModel {
class CalculatorServiceStubImpl;
class TaskSolver;

class DBusCalculatorService {
 public:
  DBusCalculatorService() = delete;
  DBusCalculatorService(const DBusCalculatorService& service) = delete;
  DBusCalculatorService(DBusCalculatorService&& service) = delete;
  DBusCalculatorService& operator=(const DBusCalculatorService& service) = delete;
  DBusCalculatorService& operator=(DBusCalculatorService&& service) = delete;

  explicit DBusCalculatorService(const std::string& name);
  ~DBusCalculatorService();

  void StartService();
  void AddTaskSolver();
 private:
  bool Initialization();

  bool is_service_ready_;
  std::string name_;
  std::list<std::unique_ptr<TaskSolver>> task_solvers_;
  TaskSynchronicalQueue task_synchronical_queue_;
  std::shared_ptr<CalculatorServiceStubImpl> service_;
  std::shared_ptr<CommonAPI::Runtime> runtime_;
};
}  // namespace DBusServiceModel

#endif  // DBUSSERVICEMODEL_SRC_SERVICE_DBUS_CALCULATOR_SERVICE_H_
