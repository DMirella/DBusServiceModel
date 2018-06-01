#include <iostream>
#include "task_manager.h"

TaskConsumerProducerQueue::TaskConsumerProducerQueue() {
  solver_thread_destroy_ = false;
  is_need_to_destroy_solver_thread_ = false;
  task_solver_thread_ = std::thread(&TaskConsumerProducerQueue::solveThreadLogic, this);
}

TaskConsumerProducerQueue::~TaskConsumerProducerQueue() {
  destroySolverThread();
}

void TaskConsumerProducerQueue::addTaskToQueue(TaskSharedPtr task) {
  std::unique_lock<std::mutex> lock(mutex_);
  queue_.push(task);
  lock.unlock();
  threads_regulator_.notify_one();

  static int call_count = 0;
  std::cout << "Reg task #" << ++call_count << std::endl;
}

void TaskConsumerProducerQueue::solveThreadLogic() {
  auto &queue_link = queue_;
  auto &is_need_to_destroy_solver_thread_link = is_need_to_destroy_solver_thread_;
  while (true) {
    std::unique_lock<std::mutex> lock(mutex_);
    threads_regulator_.wait(lock, [&queue_link, &is_need_to_destroy_solver_thread_link]() {
      return is_need_to_destroy_solver_thread_link || !queue_link.empty();
    });
    
    std::cout << "Queue size " << queue_.size() << std::endl;
    auto currentTask = queue_.front();
    currentTask->solve();
    queue_.pop();
  }
  solver_thread_destroy_ = true;
}


void TaskConsumerProducerQueue::destroySolverThread() {
  std::unique_lock<std::mutex> lock(mutex_);
  is_need_to_destroy_solver_thread_ = true;
  auto solver_thread_destroy_link = solver_thread_destroy_;
  lock.unlock();
  threads_regulator_.notify_all();
  threads_regulator_.wait(lock, [&solver_thread_destroy_link](){
    return solver_thread_destroy_link;
  });
}




