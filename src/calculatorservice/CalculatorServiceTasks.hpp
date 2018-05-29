#ifndef CALCULATOR_SERVICE_TASKS_HPP_
#define CALCULATOR_SERVICE_TASKS_HPP_

#include "Task.hpp"

#include <functional>
#include <thread>

#define HARD_TASK_TIME 200
#define TESTING_HARD_TASKS_MODEL

namespace{

using VoidFuncWithIntParam = std::function<void (int32_t _result)>;

class TaskWithTwoIntParams {
 public:
  TaskWithTwoIntParams(int value_a, int value_b) : value_a_(value_a), value_b_(value_b) { }
 protected:
  int value_a_, value_b_;
};

class TaskWithIntReply {
 public:
  TaskWithIntReply(VoidFuncWithIntParam reply) { reply_ = reply; }
 protected:
  VoidFuncWithIntParam reply_;
};

} // end namespace


class TaskSum : public Task, public TaskWithIntReply, public TaskWithTwoIntParams {
 public:
  TaskSum(int value_a, int value_b, VoidFuncWithIntParam reply) 
      : TaskWithTwoIntParams(value_a, value_b), TaskWithIntReply(reply) { }
  virtual void solve() override;
};


class TaskDeduct : public Task, public TaskWithIntReply, public TaskWithTwoIntParams {
 public:
  TaskDeduct(int value_a, int value_b, VoidFuncWithIntParam reply) 
      : TaskWithTwoIntParams(value_a, value_b), TaskWithIntReply(reply) { }
  virtual void solve() override;
};



class TaskMultiply : public Task, public TaskWithIntReply, public TaskWithTwoIntParams {
 public:
  TaskMultiply(int value_a, int value_b, VoidFuncWithIntParam reply) 
      : TaskWithTwoIntParams(value_a, value_b), TaskWithIntReply(reply) { }
  virtual void solve() override;
};



class TaskDivide : public Task, public TaskWithIntReply, public TaskWithTwoIntParams {
 public:
  TaskDivide(int value_a, int value_b, VoidFuncWithIntParam reply) 
      : TaskWithTwoIntParams(value_a, value_b), TaskWithIntReply(reply) { }
  virtual void solve() override;
 private:
  constexpr static int INFINITY = (1ll << 31) - 1; 
};


#endif  // CALCULATOR_SERVICE_TASKS_HPP_
