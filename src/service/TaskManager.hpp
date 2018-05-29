#ifndef TASK_MANAGER_HPP_
#define TASK_MANAGER_HPP_

#include "Task.hpp"
#include "SyncQueue.hpp"

#include <iostream>
#include <thread>
#include <queue>
#include <condition_variable>


namespace{

using TaskSharedPtr = std::shared_ptr<ServiceTask::Task>;
using MutexSharedPtr = std::shared_ptr<std::mutex>;
using ConditionVariableSharedPtr = std::shared_ptr<std::condition_variable>;
using TaskSyncQueue = SyncQueue<TaskSharedPtr>;
using TaskSyncQueueSharedPtr = std::shared_ptr<TaskSyncQueue>;

}  // end namespace


/**
* Synchronizes with the queue that is passed in the constructor parameters, and solves the problem as it arrives.
*/
class TaskSolver{
 public:
  TaskSolver(TaskSyncQueueSharedPtr task_queue,  
             ConditionVariableSharedPtr threads_regulator) 
      : task_queue_(task_queue),
        threads_regulator_(threads_regulator) {
    task_solver_thread_ = std::make_unique<std::thread>(&TaskSolver::taskSolverThreadLogic, this);
    mutex_ = task_queue_->mutex();  // synchronize with SyncQueue by use shared mutex
  }

  TaskSolver(const TaskSolver&) = delete;  // for security, in the future can be overridden
 private:

  /**
  * If SyncQueue have more then 0 tasks, starts to solve front task and pop it
  */
  void taskSolverThreadLogic() { 
    auto task_queue_copy = task_queue_; 
    while(true) {
      std::unique_lock<std::mutex> lock(*mutex_);
      threads_regulator_->wait(lock, [&task_queue_copy]() {
        return !task_queue_copy->empty();
      });
      
      std::cout << "Task queue size: " << task_queue_->size() << std::endl;
      auto current_task = task_queue_->front();
      current_task->solve();
      task_queue_->pop();
    }
  }

  std::unique_ptr<std::thread> task_solver_thread_;
  ConditionVariableSharedPtr threads_regulator_;
  TaskSyncQueueSharedPtr task_queue_;
  MutexSharedPtr mutex_;
};


/**
* Create a SyncQueue and TaskSolver and managed their.
*/
class TaskManager {
 using TaskSolverSharedPtr = std::shared_ptr<TaskSolver>; 

 public:
  TaskManager() {
    task_queue_ = std::make_shared<TaskSyncQueue>(); 
    threads_regulator_ = std::make_shared<std::condition_variable>();
    task_solver_ = std::make_shared<TaskSolver>(task_queue_, threads_regulator_);
  }
  
  /**
  * Add Task to SyncQueue, then notify TaskSolver by conditon_variable(threads_regulator_), display log info.
  */
  void addTaskToQueue(TaskSharedPtr task) {
    static int cnt = 0;
    std::cout << "Reg task #" << ++cnt << std::endl;
    task_queue_->push(task);
    threads_regulator_->notify_one();
  }

 private:
  TaskSyncQueueSharedPtr task_queue_;
  TaskSolverSharedPtr task_solver_;
  ConditionVariableSharedPtr threads_regulator_;
};



#endif  // TASK_MANAGER_HPP_
