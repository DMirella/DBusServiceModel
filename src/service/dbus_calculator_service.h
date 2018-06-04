#ifndef DBUSSERVICEMODEL_SRC_SERVICE_DBUS_CALCULATOR_SERVICE_H_
#define DBUSSERVICEMODEL_SRC_SERVICE_DBUS_CALCULATOR_SERVICE_H_

#include <list>
#include <memory>
#include <string>
#include <thread>

#include "calculator_service_stub_impl.h"
#include "CommonAPI/CommonAPI.hpp"
#include "task_solver.h"
#include "task_synchronical_queue.h"

namespace DBusServiceModel {
class DBusCalculatorService {
 public:
  explicit DBusCalculatorService(const std::string& name);
  DBusCalculatorService() 						 = delete;
  DBusCalculatorService(const DBusCalculatorService& service)		 = delete;
  DBusCalculatorService(DBusCalculatorService&& service) 	         = delete;
  DBusCalculatorService& operator=(const DBusCalculatorService& service) = delete;
  DBusCalculatorService& operator=(DBusCalculatorService&& service)      = delete;
  ~DBusCalculatorService();

  void StartService();
  void AddTaskSolver();
 private:
  std::string name_;
  std::list<std::unique_ptr<TaskSolver>> task_solvers_;
  std::shared_ptr<TaskSynchronicalQueue> task_synchronical_queue_;
  std::shared_ptr<CalculatorServiceStubImpl> service_;
  std::shared_ptr<CommonAPI::Runtime> runtime_;
};
}  // namespace DBusServiceModel

#endif  // DBUSSERVICEMODEL_SRC_SERVICE_DBUS_CALCULATOR_SERVICE_H_
