#ifndef DBUSSERVICEMODEL_SRC_SERVICE_CALCULATOR_SERVICE_TASKS_H_
#define DBUSSERVICEMODEL_SRC_SERVICE_CALCULATOR_SERVICE_TASKS_H_

#include <functional>

#include "task.h"

//This defines helps to test the system if it could solve a more time-consuming tasks.
#define HARD_TASK_TIME 200
#define TESTING_HARD_TASKS_MODEL

class TaskWithTwoIntParams {
 public:
  TaskWithTwoIntParams(int value_a, int value_b) : value_a_(value_a), value_b_(value_b) {}
 protected:
  const int value_a_, value_b_;
};

class TaskWithIntReply {
 public:
  explicit TaskWithIntReply(const std::function<void(int32_t _result)> &reply) : reply_(reply) {}
 protected:
  const std::function<void(int32_t _result)> reply_;
};

namespace DBusServiceModel {
class TaskSum : public Task, 
                public TaskWithIntReply,  
                public TaskWithTwoIntParams {
 public:
  TaskSum(int value_a, int value_b, const std::function<void(int32_t _result)>& reply) 
    : TaskWithTwoIntParams(value_a, value_b), TaskWithIntReply(reply) {}
  
  TaskSum() 		       		  = delete;
  TaskSum(const TaskSum& task) 		  = delete;
  TaskSum(TaskSum&& task)      		  = delete;
  TaskSum& operator=(const TaskSum& task) = delete;
  TaskSum& operator=(TaskSum&& task) 	  = delete;
  ~TaskSum() {}
  virtual void Solve() override;
};

class TaskDeduct : public Task, 
                   public TaskWithIntReply, 
                   public TaskWithTwoIntParams {
 public:
  TaskDeduct(int value_a, int value_b, const std::function<void(int32_t _result)>& reply) 
    : TaskWithTwoIntParams(value_a, value_b), TaskWithIntReply(reply) {}
  TaskDeduct() 		             		= delete;
  TaskDeduct(const TaskDeduct& task) 		= delete;
  TaskDeduct(TaskDeduct&& task)      		= delete;
  TaskDeduct& operator=(const TaskDeduct& task) = delete;
  TaskDeduct& operator=(TaskDeduct&& task) 	= delete;
  ~TaskDeduct() {}
  virtual void Solve() override;
};

class TaskMultiply : public Task, 
                     public TaskWithIntReply, 
                     public TaskWithTwoIntParams {
 public:
  TaskMultiply(int value_a, int value_b, const std::function<void(int32_t _result)>& reply) 
    : TaskWithTwoIntParams(value_a, value_b), TaskWithIntReply(reply) {}
  TaskMultiply() 		         	    = delete;
  TaskMultiply(const TaskMultiply& task) 	    = delete;
  TaskMultiply(TaskMultiply&& task)      	    = delete;
  TaskMultiply& operator=(const TaskMultiply& task) = delete;
  TaskMultiply& operator=(TaskMultiply&& task) 	    = delete;
  ~TaskMultiply() {}
  virtual void Solve() override;
};

class TaskDivide : public Task, 
		   public TaskWithIntReply, 
		   public TaskWithTwoIntParams {
 public:
  TaskDivide(int value_a, int value_b, const std::function<void(int32_t _result)>& reply) 
    : TaskWithTwoIntParams(value_a, value_b), TaskWithIntReply(reply) {}
  TaskDivide() 		             		= delete;
  TaskDivide(const TaskDivide& task) 		= delete;
  TaskDivide(TaskDivide&& task)      		= delete;
  TaskDivide& operator=(const TaskDivide& task) = delete;
  TaskDivide& operator=(TaskDivide&& task) 	= delete;
  ~TaskDivide() {}
  virtual void Solve() override;
};
}  // namespace DBusServiceModel

#endif  // DBUSSERVICEMODEL_SRC_SERVICE_CALCULATOR_SERVICE_TASKS_H_
