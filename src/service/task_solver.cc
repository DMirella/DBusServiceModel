#include "task_solver.h"

#include <iostream>

namespace DBusServiceModel {
TaskSolver::TaskSolver(const std::shared_ptr<TaskSynchronicalQueue>& task_synchronical_queue) 
  : task_synchronical_queue_(task_synchronical_queue) {
  is_solver_thread_destroyed_ = true;
  StartSolverThread();
}

TaskSolver::~TaskSolver() {
  TryToDestroySolverThread();
  task_solver_thread_.join();
}

void TaskSolver::StartSolverThread() {
  is_solver_thread_need_to_destroy_ = false;
  if (is_solver_thread_destroyed_) {
    is_solver_thread_destroyed_ = false;
    task_solver_thread_ = std::thread(&TaskSolver::TaskSolverThreadLogic, this);
  }
}

void TaskSolver::TryToDestroySolverThread() {
  if (is_solver_thread_destroyed_) { return; }
  is_solver_thread_need_to_destroy_ = true;
  is_solver_thread_destroyed_ = false;
}

void TaskSolver::TaskSolverThreadLogic() {
  while (!is_solver_thread_need_to_destroy_) {
    if (auto task_synchronical_queue = task_synchronical_queue_.lock()) {
      auto current_task = task_synchronical_queue->Remove();
      if (current_task == nullptr) {
        TryToDestroySolverThread();
	continue;
      }
      current_task->Solve();
    } else {
      TryToDestroySolverThread();
    }
  }
  is_solver_thread_destroyed_ = true;
}
}  // namespace DBusServiceModel
