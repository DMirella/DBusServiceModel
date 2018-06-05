#include "task_synchronical_queue.h"

#include <iostream>

namespace DBusServiceModel {
TaskSynchronicalQueue::TaskSynchronicalQueue() 
  : task_recieve_(true), is_need_to_destroy_(false){
}

TaskSynchronicalQueue::~TaskSynchronicalQueue() {
  Destroy();
}

bool TaskSynchronicalQueue::AddTask(const std::shared_ptr<Task>& task) {
  if (!task_recieve_ || task == nullptr) {
    return false;
  }
  std::lock_guard<std::mutex> lock(mutex_);
  queue_.push(task);
  static int cnt = 0;
  std::cout << "Reg task #" << ++cnt << std::endl; 
  condition_variable_.notify_one();
  return true;
}

std::shared_ptr<Task> TaskSynchronicalQueue::RemoveTask() {
  std::unique_lock<std::mutex> lock(mutex_);
  condition_variable_.wait(lock, [this]() {
    return !queue_.empty() || is_need_to_destroy_;
  });
  if (is_need_to_destroy_ && queue_.empty()) {
    return nullptr;
  }
  std::cout << "Queue size " << queue_.size() << std::endl; 
  auto current_task = queue_.front();
  queue_.pop();
  return current_task;
}

void TaskSynchronicalQueue::Destroy() {
  set_task_recieve(false);
  is_need_to_destroy_ = true;
  while (!queue_.empty()) {
    condition_variable_.notify_one();
  }
  condition_variable_.notify_all();
}
}  // namespace DBusServiceModel
