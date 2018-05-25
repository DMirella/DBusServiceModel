#ifndef TASKMANAGER_H_
#define TASKMANAGER_H_

#include "Task.hpp"

#include <thread>
#include <queue>
#include <condition_variable>

class TaskQuery;

namespace{

using MutexPtr = std::shared_ptr<std::mutex>;
using TaskQueryPtr = std::shared_ptr<TaskQuery>;
using ConditionVariablePtr = std::shared_ptr<std::condition_variable>;
using TaskPtr = std::shared_ptr<Task>;

}


class TaskQuery{

 public:
  TaskQuery(MutexPtr mutex) : mutex_(mutex) { }
  void addTaskToQuery(TaskPtr task) { 
    std::lock_guard<std::mutex> lock(*mutex_);
    task_query_.push(task); 
  }

  inline void popTask() { task_query_.pop(); }

  inline TaskPtr frontTask() const { return task_query_.front(); }
  inline MutexPtr mutex() const { return mutex_; }
  inline bool isTaskQueryEmpty() const { return task_query_.empty(); }
 private:
  MutexPtr mutex_;
  std::queue<TaskPtr> task_query_;
};


class TaskSolver{
 public:
  TaskSolver(TaskQueryPtr task_query, 
             ConditionVariablePtr threads_regulator) 
      : task_query_(task_query), 
        task_solver_thread_(std::thread(&TaskSolver::taskSolverThreadLogic, this)),
        threads_regulator_(threads_regulator) {
    mutex_ = task_query_->mutex();
  }
 private:
  void taskSolverThreadLogic() { 
    //std::this_thread::sleep_for(std::chrono::seconds(2));
    std::unique_lock<std::mutex> lock(*mutex_);
    auto task_query_copy = task_query_;
    while(true) {
      threads_regulator_->wait(lock, [&task_query_copy]() {
        return !task_query_copy->isTaskQueryEmpty();
      });

      auto currentTask = task_query_->frontTask();
      currentTask->solve();
      task_query_->popTask();
    }
  }

  std::thread task_solver_thread_;
  ConditionVariablePtr threads_regulator_;
  TaskQueryPtr task_query_;
  MutexPtr mutex_;
};



class TaskManager {
 using TaskSolverPtr = std::shared_ptr<TaskSolver>; 
 public:
  TaskManager() 
     /* : mutex_(std::make_shared<std::mutex>()),
	task_query_(std::make_shared<TaskQuery>(mutex_)), 
	threads_regulator_(std::make_shared<std::condition_variable>()),
	task_solver_(task_query_, threads_regulator_)*/{
    mutex_ = std::make_shared<std::mutex>();
    task_query_ = std::make_shared<TaskQuery>(mutex_); 
    threads_regulator_ = std::make_shared<std::condition_variable>();
    task_solver_ = std::make_shared<TaskSolver>(task_query_, threads_regulator_);
  }

  void addTaskToQuery(TaskPtr task) {
    task_query_->addTaskToQuery(task);
    threads_regulator_->notify_all();
  }

 private:

  TaskQueryPtr  task_query_;
  TaskSolverPtr task_solver_;
  ConditionVariablePtr threads_regulator_;
  MutexPtr mutex_;
};



#endif  // TASKMANAGER_H_
