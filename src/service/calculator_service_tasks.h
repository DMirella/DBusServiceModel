#ifndef DBUSSERVICEMODEL_SRC_SERVICE_CALCULATOR_SERVICE_TASKS_H_
#define DBUSSERVICEMODEL_SRC_SERVICE_CALCULATOR_SERVICE_TASKS_H_

#include <functional>
#include <thread>
#include "task.h"

//This defines helps to test the system if it could solve a more time-consuming tasks.
#define HARD_TASK_TIME 200
#define TESTING_HARD_TASKS_MODEL

namespace CalculatorServiceTask {
namespace{
const int kInfinity = 2010101010;

class TaskWithTwoIntParams {
 public:
  TaskWithTwoIntParams(const int value_a, const int value_b) 
    : value_a_(value_a), value_b_(value_b) {}
 protected:
  const int value_a_, value_b_;
};
class TaskWithIntReply {
 public:
  explicit TaskWithIntReply(const std::function<void(int32_t _result)> &reply) : reply_(reply) {}
 protected:
  const std::function<void(int32_t _result)> reply_;
};
}  // namespace

class TaskSum : public ServiceTask::Task, 
                public TaskWithIntReply,  
                public TaskWithTwoIntParams {
 public:
  TaskSum(const int value_a, const int value_b, const std::function<void(int32_t _result)>& reply) 
    : TaskWithTwoIntParams(value_a, value_b), TaskWithIntReply(reply) {}
  
  TaskSum() 		       = delete;
  TaskSum(const TaskSum& task) = delete;
  TaskSum(TaskSum&& task)      = delete;
  virtual void Solve() override;
};

class TaskDeduct : public ServiceTask::Task, 
                   public TaskWithIntReply, 
                   public TaskWithTwoIntParams {
 public:
  TaskDeduct(const int value_a, const int value_b, const std::function<void(int32_t _result)>& reply) 
    : TaskWithTwoIntParams(value_a, value_b), TaskWithIntReply(reply) {}
  TaskDeduct() 		             = delete;
  TaskDeduct(const TaskDeduct& task) = delete;
  TaskDeduct(TaskDeduct&& task)      = delete;
  virtual void Solve() override;
};

class TaskMultiply : public ServiceTask::Task, 
                     public TaskWithIntReply, 
                     public TaskWithTwoIntParams {
 public:
  TaskMultiply(const int value_a, const int value_b, const std::function<void(int32_t _result)>& reply) 
    : TaskWithTwoIntParams(value_a, value_b), TaskWithIntReply(reply) {}
  TaskMultiply() 		         = delete;
  TaskMultiply(const TaskMultiply& task) = delete;
  TaskMultiply(TaskMultiply&& task)      = delete;
  virtual void Solve() override;
};

class TaskDivide : public ServiceTask::Task, 
		   public TaskWithIntReply, 
		   public TaskWithTwoIntParams {
 public:
  TaskDivide(const int value_a, const int value_b, const std::function<void(int32_t _result)>& reply) 
    : TaskWithTwoIntParams(value_a, value_b), TaskWithIntReply(reply) {}
  TaskDivide() 		             = delete;
  TaskDivide(const TaskDivide& task) = delete;
  TaskDivide(TaskDivide&& task)      = delete;
  virtual void Solve() override;
};
}  // namespace CalculatorServiceTask

#endif  // DBUSSERVICEMODEL_SRC_SERVICE_CALCULATOR_SERVICE_TASKS_H_
