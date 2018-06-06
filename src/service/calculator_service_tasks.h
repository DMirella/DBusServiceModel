#ifndef DBUSSERVICEMODEL_SRC_SERVICE_CALCULATOR_SERVICE_TASKS_H_
#define DBUSSERVICEMODEL_SRC_SERVICE_CALCULATOR_SERVICE_TASKS_H_

#include <functional>

#include "task.h"
//This defines helps to test the system if it could solve a more time-consuming tasks.
#define TESTING_HARD_TASKS_MODEL

namespace DBusServiceModel {
class TaskSum : public TaskWithTwoIntParamsAndIntReply {
 public:
  TaskSum() = delete;
  TaskSum(const TaskSum& task) = delete;
  TaskSum(TaskSum&& task) = delete;
  TaskSum& operator=(const TaskSum& task) = delete;
  TaskSum& operator=(TaskSum&& task) = delete;

  TaskSum(int value_a, int value_b, const std::function<void(int)>& reply) 
    : TaskWithTwoIntParamsAndIntReply(value_a, value_b, reply) {}
  ~TaskSum() {}
  // Task
  virtual void Solve() override;
};

class TaskDeduct : public TaskWithTwoIntParamsAndIntReply {
 public:
  TaskDeduct() = delete;
  TaskDeduct(const TaskDeduct& task) = delete;
  TaskDeduct(TaskDeduct&& task) = delete;
  TaskDeduct& operator=(const TaskDeduct& task) = delete;
  TaskDeduct& operator=(TaskDeduct&& task) = delete;

  TaskDeduct(int value_a, int value_b, const std::function<void(int)>& reply) 
    : TaskWithTwoIntParamsAndIntReply(value_a, value_b, reply) {}
  ~TaskDeduct() {}
  // Task
  virtual void Solve() override;
};

class TaskMultiply : public TaskWithTwoIntParamsAndIntReply {
 public:
  TaskMultiply() = delete;
  TaskMultiply(const TaskMultiply& task) = delete;
  TaskMultiply(TaskMultiply&& task) = delete;
  TaskMultiply& operator=(const TaskMultiply& task) = delete;
  TaskMultiply& operator=(TaskMultiply&& task) = delete;

  TaskMultiply(int value_a, int value_b, const std::function<void(int)>& reply) 
    : TaskWithTwoIntParamsAndIntReply(value_a, value_b, reply) {}
  ~TaskMultiply() {}
  // Task
  virtual void Solve() override;
};

class TaskDivide : public TaskWithTwoIntParamsAndIntReply {
 public:
  TaskDivide() = delete;
  TaskDivide(const TaskDivide& task) = delete;
  TaskDivide(TaskDivide&& task) = delete;
  TaskDivide& operator=(const TaskDivide& task) = delete;
  TaskDivide& operator=(TaskDivide&& task) = delete;

  TaskDivide(int value_a, int value_b, const std::function<void(int)>& reply) 
    : TaskWithTwoIntParamsAndIntReply(value_a, value_b, reply) {}
  ~TaskDivide() {}
  // Task
  virtual void Solve() override;
};
}  // namespace DBusServiceModel

#endif  // DBUSSERVICEMODEL_SRC_SERVICE_CALCULATOR_SERVICE_TASKS_H_
