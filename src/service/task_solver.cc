#include "task_solver.h"

#include <iostream>

namespace DBusServiceModel {
TaskSolver::TaskSolver(std::shared_ptr<TaskSynchronicalQueue> task_synchronical_queue) 
  : task_synchronical_queue_(task_synchronical_queue) {
  task_solver_thread_ = std::thread(&TaskSolver::TaskSolverThreadLogic, this);
}

TaskSolver::~TaskSolver() {
  std::cout << "TaskSolver destr\n";
  task_solver_thread_.join();
}

void TaskSolver::TaskSolverThreadLogic() {
  while (true) {
    if (auto task_synchronical_queue = task_synchronical_queue_.lock()) {
      task_synchronical_queue->SolveAndPopFront();
    } else {
      break;
    }
  }
}

}  // namespace DBusServiceModel
