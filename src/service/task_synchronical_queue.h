#ifndef DBUSSERVICEMODEL_SRC_SERVICE_TASK_SYNCHRONICAL_QUEUE_H_
#define DBUSSERVICEMODEL_SRC_SERVICE_TASK_SYNCHRONICAL_QUEUE_H_

#include <atomic>
#include <condition_variable>
#include <memory>
#include <mutex>
#include <queue>
#include <thread>

namespace DBusServiceModel {
class Task;
class TaskSynchronicalQueue {
 public:
  TaskSynchronicalQueue(const TaskSynchronicalQueue& queue) = delete;
  TaskSynchronicalQueue(TaskSynchronicalQueue&& queue) = delete;
  TaskSynchronicalQueue& operator=(const TaskSynchronicalQueue& queue) = delete;
  TaskSynchronicalQueue& operator=(TaskSynchronicalQueue&& queue) = delete;

  TaskSynchronicalQueue();
  ~TaskSynchronicalQueue();

  bool AddTask(const std::shared_ptr<Task>& task);
  std::shared_ptr<Task> RemoveTask();
  void Destroy();

  inline void set_task_recieve(bool mode) { task_recieve_ = mode; }
 private:
  std::atomic<bool> task_recieve_;
  std::atomic<bool> is_need_to_destroy_;
  std::queue<std::shared_ptr<Task>> queue_;
  std::mutex mutex_;
  std::condition_variable condition_variable_;
};
}  // namespace DBusServiceModel

#endif  // DBUSSERVICEMODEL_SRC_SERVICE_TASK_SYNCHRONICAL_QUEUE_H_
