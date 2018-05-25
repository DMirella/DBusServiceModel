#ifndef TASKMANAGER_H_
#define TASKMANAGER_H_

#include <thread>
#include <queue>
#include <condition_variable>

class Task{
};


class TaskQuery{
 public:
  void addTaskToQuery(std::shared_ptr<Task> task);
  inline bool isTaskQueryEmpty() const { return task_query_.empty(); }
 private:
  std::queue<std::shared_ptr<Task>> task_query_;
};


class TaskSolver{
 public:
  TaskSolver(std::shared_ptr<TaskQuery> task_query, std::shared_ptr<std::condition_variable> threads_regulator) 
      : task_query_(task_query), task_solver_thread_(std::thread(&TaskSolver::taskSolverThreadLogic, this)),
        threads_regulator_(threads_regulator) { 
  }
 private:
  void taskSolverThreadLogic() { 
    std::unique_lock<std::mutex> lock;
    auto task_query_copy = task_query_;
    while(true) {
      threads_regulator_->wait(lock, [&task_query_copy]() {
        return !task_query_copy->isTaskQueryEmpty();
      });
    }
  }

  std::thread task_solver_thread_;
  std::shared_ptr<std::condition_variable> threads_regulator_;
  std::shared_ptr<TaskQuery> task_query_;
};



class TaskManager {
 public:
  TaskManager() 
      : task_query_(std::make_shared<TaskQuery>()), 
	threads_regulator_(std::make_shared<std::condition_variable>()),
	task_solver_(task_query_, threads_regulator_){
    
  }

  void addTaskToQuery(std::shared_ptr<Task> task);

 private:

  std::shared_ptr<TaskQuery> task_query_;
  TaskSolver task_solver_;
  std::shared_ptr<std::condition_variable> threads_regulator_;
};

#endif  //TASKMANAGER_H_
