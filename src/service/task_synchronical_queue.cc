#include "task_synchronical_queue.h"

#include <iostream>

namespace DBusServiceModel {
TaskSynchronicalQueue::~TaskSynchronicalQueue() {
  std::cout << "TaskSynchronicalQueue destr\n";
}

void TaskSynchronicalQueue::Push(const std::shared_ptr<Task>& task) {
  static int cnt = 0;
  std::unique_lock<std::mutex> lock(mutex_);
  queue_.push(task);
  std::cout << "Reg task #" << ++cnt << std::endl; 
  lock.unlock();
  condition_variable_.notify_all();
}

void TaskSynchronicalQueue::SolveAndPopFront() {
  std::unique_lock<std::mutex> lock(mutex_);
  auto &queue_link = queue_;
  condition_variable_.wait(lock, [&queue_link]() {
    return !queue_link.empty();
  });
  std::cout << "Queue size " << queue_.size() << std::endl; 
  auto current_task = queue_.front();
  current_task->Solve();
  queue_.pop();
}
}  // namespace DBusServiceModel
