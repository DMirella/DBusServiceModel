#include "task_solver.h"

#include <iostream>

#include "task.h"
#include "task_synchronical_queue.h"

namespace DBusServiceModel {
TaskSolver::TaskSolver(TaskSynchronicalQueue* task_synchronical_queue) 
    : task_synchronical_queue_(task_synchronical_queue), 
      is_solver_thread_destroyed_(true),
      is_solver_thread_need_to_destroy_(false) {
  if (task_synchronical_queue_ == nullptr) {
    std::cerr << "Error in TaskSolver::TaskSolver(...): task_synchronical_queue_ == nullptr\n";
    return;
  }
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
  if (is_solver_thread_destroyed_) {
    is_solver_thread_need_to_destroy_ = true;
  }
}

void TaskSolver::TaskSolverThreadLogic() {
  while (!is_solver_thread_need_to_destroy_) {
    if (task_synchronical_queue_ == nullptr) {
      std::cerr << "Error in TaskSolver::TaskSolverThreadLogic(): task_synchronical_queue_ == nullptr\n";
      break;
    }
    auto current_task = task_synchronical_queue_->RemoveTask();
    if (current_task == nullptr) {
      break;
    }
    current_task->Solve();
  }
  is_solver_thread_destroyed_ = true;
}
}  // namespace DBusServiceModel
