#include "task_synchronical_queue.h"

#include <iostream>

namespace DBusServiceModel {
TaskSynchronicalQueue::TaskSynchronicalQueue() {
  Continue();
}

TaskSynchronicalQueue::~TaskSynchronicalQueue() {
  Stop();
}

bool TaskSynchronicalQueue::Add(const std::shared_ptr<Task>& task) {
  if (is_stopped_ || task == nullptr) {
    return false;
  }
  std::unique_lock<std::mutex> lock(mutex_);
  queue_.push(task);
  static int cnt = 0;
  std::cout << "Reg task #" << ++cnt << std::endl; 
  lock.unlock();
  condition_variable_.notify_one();
  return true;
}

std::shared_ptr<Task> TaskSynchronicalQueue::Remove() {
  std::unique_lock<std::mutex> lock(mutex_);
  condition_variable_.wait(lock, [this]() {
    return !queue_.empty() || is_stopped_;
  });
  if (is_stopped_) {
    return nullptr;
  }
  std::cout << "Queue size " << queue_.size() << std::endl; 
  auto current_task = queue_.front();
  queue_.pop();
  return current_task;
}

void TaskSynchronicalQueue::Stop() {
  is_stopped_ = true;
  condition_variable_.notify_all();
}

void TaskSynchronicalQueue::Continue() {
  is_stopped_ = false;
}
}  // namespace DBusServiceModel
