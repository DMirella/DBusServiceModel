#ifndef DBUSSERVICEMODEL_SRC_SERVICE_TASK_SYNCHRONICAL_QUEUE_H_
#define DBUSSERVICEMODEL_SRC_SERVICE_TASK_SYNCHRONICAL_QUEUE_H_

#include <atomic>
#include <condition_variable>
#include <mutex>
#include <queue>
#include <thread>
#include "task.h"

namespace DBusServiceModel {
class TaskSynchronicalQueue {
 public:
  TaskSynchronicalQueue();
  TaskSynchronicalQueue(const TaskSynchronicalQueue& queue) 	       = delete;
  TaskSynchronicalQueue(TaskSynchronicalQueue&& queue) 		       = delete;
  TaskSynchronicalQueue& operator=(const TaskSynchronicalQueue& queue) = delete;
  TaskSynchronicalQueue& operator=(TaskSynchronicalQueue&& queue)      = delete;
  ~TaskSynchronicalQueue();

  bool Add(const std::shared_ptr<Task>& task);
  std::shared_ptr<Task> Remove();

  void Stop();
  void Continue();
 private:
  std::atomic<bool> is_stopped_;
  std::queue<std::shared_ptr<Task>> queue_;
  std::mutex mutex_;
  std::condition_variable condition_variable_;
};
}  // namespace DBusServiceModel

#endif  // DBUSSERVICEMODEL_SRC_SERVICE_TASK_SYNCHRONICAL_QUEUE_H_
