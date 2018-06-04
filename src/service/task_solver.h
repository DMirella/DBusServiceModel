#ifndef DBUSSERVICEMODEL_SRC_SERVICE_TASK_SOLVER_H_
#define DBUSSERVICEMODEL_SRC_SERVICE_TASK_SOLVER_H_

#include <atomic>
#include <memory>
#include <thread>

#include "task_synchronical_queue.h"

namespace DBusServiceModel {
class TaskSolver {
 public:
  TaskSolver(const std::shared_ptr<TaskSynchronicalQueue>& task_synchronical_queue);
  TaskSolver() 					       = delete;
  TaskSolver(const TaskSolver& task_solver) 	       = delete;
  TaskSolver(TaskSolver&& task_solver) 		       = delete;
  TaskSolver& operator=(const TaskSolver& task_solver) = delete;
  TaskSolver& operator=(TaskSolver&& task_solver)      = delete;
  ~TaskSolver();

  void StartSolverThread();
  void TryToDestroySolverThread();
 private:
  void TaskSolverThreadLogic();

  std::weak_ptr<TaskSynchronicalQueue> task_synchronical_queue_;
  std::thread task_solver_thread_;
  std::atomic<bool> is_solver_thread_need_to_destroy_;
  std::atomic<bool> is_solver_thread_destroyed_;
};
}  // namespace DBusServiceModel

#endif  // DBUSSERVICEMODEL_SRC_SERVICE_TASK_SOLVER_H_
