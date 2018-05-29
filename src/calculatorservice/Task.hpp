#ifndef TASK_H_
#define TASK_H_

#include <functional>
#include <thread>
#include <iostream>


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



class Task {
 public:
  virtual void solve() = 0;
};


class TaskSum : public Task, public TaskWithIntReply, public TaskWithTwoIntParams {
 public:
  TaskSum(int value_a, int value_b, VoidFuncWithIntParam reply) 
      : TaskWithTwoIntParams(value_a, value_b), TaskWithIntReply(reply) { }
  virtual void solve() override {
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "TaskSum: " << value_a_ << " " << value_b_ << std::endl;
    reply_(value_a_ + value_b_);
  }
};


class TaskDeduct : public Task, public TaskWithIntReply, public TaskWithTwoIntParams {
 public:
  TaskDeduct(int value_a, int value_b, VoidFuncWithIntParam reply) 
      : TaskWithTwoIntParams(value_a, value_b), TaskWithIntReply(reply) { }
  virtual void solve() override {
    reply_(value_a_ - value_b_);
  }
};



class TaskMultiply : public Task, public TaskWithIntReply, public TaskWithTwoIntParams {
 public:
  TaskMultiply(int value_a, int value_b, VoidFuncWithIntParam reply) 
      : TaskWithTwoIntParams(value_a, value_b), TaskWithIntReply(reply) { }
  virtual void solve() override {
    reply_(value_a_ * value_b_);
  }
};



class TaskDivide : public Task, public TaskWithIntReply, public TaskWithTwoIntParams {
 public:
  TaskDivide(int value_a, int value_b, VoidFuncWithIntParam reply) 
      : TaskWithTwoIntParams(value_a, value_b), TaskWithIntReply(reply) { }
  virtual void solve() override {
    int answer = INFINITY;
    if(value_b_ != 0) answer = value_a_ / value_b_;
    reply_(answer);
  }
 private:
  constexpr static int INFINITY = (1ll << 31) - 1; 
};


#endif  // TASK_H_
