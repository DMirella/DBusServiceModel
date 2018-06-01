#include <iostream>
#include "calculator_service_tasks.h"

void TaskSum::solve() {
#ifdef TESTING_HARD_TASKS_MODEL
  std::this_thread::sleep_for(std::chrono::milliseconds(HARD_TASK_TIME));
#endif
  reply_(value_a_ + value_b_);
}

void TaskDeduct::solve() {
#ifdef TESTING_HARD_TASKS_MODEL
  std::this_thread::sleep_for(std::chrono::milliseconds(HARD_TASK_TIME));
#endif
  reply_(value_a_ - value_b_);
}

void TaskMultiply::solve() {
#ifdef TESTING_HARD_TASKS_MODEL
  std::this_thread::sleep_for(std::chrono::milliseconds(HARD_TASK_TIME));
#endif
  reply_(value_a_ * value_b_);
}

void TaskDivide::solve() {
#ifdef TESTING_HARD_TASKS_MODEL
  std::this_thread::sleep_for(std::chrono::milliseconds(HARD_TASK_TIME));
#endif
  if (value_b_ == 0) {
    std::cerr << "In TaskDivide::solve(): divide by 0\n";
    return;
  }
  reply_(value_a_ / value_b_);
}
