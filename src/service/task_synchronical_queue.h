#ifndef DBUSSERVICEMODEL_SRC_SERVICE_TASK_SYNCHRONICAL_QUEUE_H_
#define DBUSSERVICEMODEL_SRC_SERVICE_TASK_SYNCHRONICAL_QUEUE_H_

#include <condition_variable>
#include <mutex>
#include <queue>
#include <thread>
#include "task.h"

namespace DBusServiceModel {
class TaskSynchronicalQueue {
 public:
  ~TaskSynchronicalQueue();
  void Push(const std::shared_ptr<Task>& task);
  void SolveAndPopFront();
 private:
  std::queue<std::shared_ptr<Task>> queue_;
  std::mutex mutex_;
  std::condition_variable condition_variable_;
};
}  // namespace DBusServiceModel

#endif  // DBUSSERVICEMODEL_SRC_SERVICE_TASK_SYNCHRONICAL_QUEUE_H_
