#ifndef DBUSSERVICEMODEL_SRC_SERVICE_TASK_SOLVER_H_
#define DBUSSERVICEMODEL_SRC_SERVICE_TASK_SOLVER_H_

#include <memory>
#include <thread>

#include "task_synchronical_queue.h"

namespace DBusServiceModel {
class TaskSolver {
 public:
  TaskSolver(std::shared_ptr<TaskSynchronicalQueue> task_synchronical_queue);
  TaskSolver(TaskSolver&& task_solver) = delete;
  TaskSolver() = delete;
  TaskSolver(const TaskSolver& task_solver) = delete;
  TaskSolver& operator=(const TaskSolver& task_solver) = delete;
  TaskSolver& operator=(TaskSolver&& task_solver) = delete;
  ~TaskSolver();
  
 private:
  void TaskSolverThreadLogic();

  std::weak_ptr<TaskSynchronicalQueue> task_synchronical_queue_;
  std::thread task_solver_thread_;
  bool is_need_destroy_solver_thread_;
};
}  // namespace DBusServiceModel

#endif  // DBUSSERVICEMODEL_SRC_SERVICE_TASK_SOLVER_H_
