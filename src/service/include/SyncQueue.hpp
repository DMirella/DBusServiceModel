#ifndef SYNC_QUEUE_HPP_
#define SYNC_QUEUE_HPP_

#include <memory>
#include <mutex>
#include <queue>

/* This Queue can be synchronized by shared mutex */
template<typename QueueType_>
class SyncQueue {
 using MutexSharedPtr = std::shared_ptr<std::mutex>;
 public:
  SyncQueue() { mutex_ = std::make_shared<std::mutex>(); }

  inline void push(QueueType_ el) { 
    std::lock_guard<std::mutex> lock(*mutex_);
    queue_.push(el); 
  }
  inline size_t size() const { return queue_.size(); }
  inline void pop() { queue_.pop(); }
  inline QueueType_ front() const { return queue_.front(); }
  inline bool empty() const { return queue_.empty(); }
  
  inline void set_mutex(MutexSharedPtr mutex) { mutex_ = mutex; }
  inline MutexSharedPtr mutex() const { return mutex_; }
 private:
  MutexSharedPtr mutex_;
  std::queue<QueueType_> queue_;
};

#endif  // SYNC_QUEUE_HPP_
