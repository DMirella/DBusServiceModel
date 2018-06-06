#ifndef DBUSSERVICEMODEL_SRC_SERVICE_INCLUDE_TASK_H_
#define DBUSSERVICEMODEL_SRC_SERVICE_INCLUDE_TASK_H_

#include <functional>

namespace DBusServiceModel {
class Task {
 public:
  virtual ~Task() {}
  //In this function you must write your solve task logic.
  virtual void Solve() = 0;
};

class TaskWithTwoIntParamsAndIntReply : public Task {
 public:
  TaskWithTwoIntParamsAndIntReply(int value_a, int value_b, const std::function<void(int)>& reply)
    : value_a_(value_a), value_b_(value_b), reply_(reply) {}
  virtual ~TaskWithTwoIntParamsAndIntReply() {}
 protected:
  int value_a_, value_b_;
  std::function<void(int)> reply_;
};
}  // namespace DBusServiceModel

#endif  // DBUSSERVICEMODEL_SRC_SERVICE_INCLUDE_TASK_H_
