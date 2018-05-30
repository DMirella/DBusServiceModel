#ifndef CALCULATOR_SERVICE_TASKS_HPP_
#define CALCULATOR_SERVICE_TASKS_HPP_

#include "Task.hpp"
#include <functional>
#include <thread>

/*This defines helps to test the system if it 
  could solve a more time-consuming tasks.*/
#define HARD_TASK_TIME 200
#define TESTING_HARD_TASKS_MODEL

namespace{
using VoidFuncWithIntParam = std::function<void (int32_t _result)>;

/* I thought that it was a good solution to avoid tautology declaring classes with similar data */
class TaskWithTwoIntParams {
 public:
  TaskWithTwoIntParams(int value_a, int value_b) 
    : value_a_(value_a), value_b_(value_b) { }
 protected:
  int value_a_, value_b_;
};

class TaskWithIntReply {
 public:
  explicit TaskWithIntReply(VoidFuncWithIntParam reply) { reply_ = reply; }
 protected:
  VoidFuncWithIntParam reply_;
};
/************************************************************************************************/

} // namespace

/* The tasks do the elementary operations(+, -, *, /) with value_a_ and value_b_ 
 * and return the result by calling the reply_-function 		      */
class TaskSum : public ServiceTask::Task, 
                public TaskWithIntReply,  
                public TaskWithTwoIntParams {
 public:
  TaskSum(int value_a, int value_b, VoidFuncWithIntParam reply) 
    : TaskWithTwoIntParams(value_a, value_b), TaskWithIntReply(reply) { }
  virtual void solve() override;
};

class TaskDeduct : public ServiceTask::Task, 
                   public TaskWithIntReply, 
                   public TaskWithTwoIntParams {
 public:
  TaskDeduct(int value_a, int value_b, VoidFuncWithIntParam reply) 
    : TaskWithTwoIntParams(value_a, value_b), TaskWithIntReply(reply) { }
  virtual void solve() override;
};

class TaskMultiply : public ServiceTask::Task, 
                     public TaskWithIntReply, 
                     public TaskWithTwoIntParams {
 public:
  TaskMultiply(int value_a, int value_b, VoidFuncWithIntParam reply) 
    : TaskWithTwoIntParams(value_a, value_b), TaskWithIntReply(reply) { }
  virtual void solve() override;
};

class TaskDivide : public ServiceTask::Task, 
		   public TaskWithIntReply, 
		   public TaskWithTwoIntParams {
 public:
  TaskDivide(int value_a, int value_b, VoidFuncWithIntParam reply) 
    : TaskWithTwoIntParams(value_a, value_b), TaskWithIntReply(reply) { }
  virtual void solve() override;
 private:
  constexpr static int kInfinity = (1ll << 31) - 1;  // for x/0 case, local infinity
};

#endif  // CALCULATOR_SERVICE_TASKS_HPP_
