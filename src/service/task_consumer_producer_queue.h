#ifndef DBUSSERVICEMODEL_SRC_SERVICE_TASK_CONSUMER_PRODUCER_QUEUE_H_
#define DBUSSERVICEMODEL_SRC_SERVICE_TASK_CONSUMER_PRODUCER_QUEUE_H_

#include <condition_variable>
#include <mutex>
#include <queue>
#include <thread>
#include "task.h"

namespace{
using TaskSharedPtr = std::shared_ptr<ServiceTask::Task>;
}  // namespace

namespace TaskConsumerProducerQueue {
class TaskConsumerProducerQueue {
 public:
  TaskConsumerProducerQueue();
  TaskConsumerProducerQueue(const TaskConsumerProducerQueue& task_consumer_producer_queue) = delete;
  TaskConsumerProducerQueue(TaskConsumerProducerQueue&& task_consumer_producer_queue)      = delete;
  ~TaskConsumerProducerQueue();

  void addTaskToQueue(const TaskSharedPtr& task);
 private:
  void solveThreadLogic();
  void startSolverThread();
  void destroySolverThread();

  std::thread task_solver_thread_;
  std::queue<TaskSharedPtr> queue_;
  std::condition_variable threads_regulator_;
  std::mutex mutex_;

  bool solver_thread_destroy_;
  bool is_need_to_destroy_solver_thread_;
};
}  // namespace TaskConsumerProducerQueue

#endif  // DBUSSERVICEMODEL_SRC_SERVICE_TASK_CONSUMER_PRODUCER_QUEUE_H_
