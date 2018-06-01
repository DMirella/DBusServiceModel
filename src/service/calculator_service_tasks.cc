#include <chrono>
#include <iostream>
#include <thread>
#include "calculator_service_tasks.h"

void CalculatorServiceTask::TaskSum::Solve() {
#ifdef TESTING_HARD_TASKS_MODEL
  std::this_thread::sleep_for(std::chrono::milliseconds(HARD_TASK_TIME));
#endif
  reply_(value_a_ + value_b_);
}

void CalculatorServiceTask::TaskDeduct::Solve() {
#ifdef TESTING_HARD_TASKS_MODEL
  std::this_thread::sleep_for(std::chrono::milliseconds(HARD_TASK_TIME));
#endif
  reply_(value_a_ - value_b_);
}

void CalculatorServiceTask::TaskMultiply::Solve() {
#ifdef TESTING_HARD_TASKS_MODEL
  std::this_thread::sleep_for(std::chrono::milliseconds(HARD_TASK_TIME));
#endif
  reply_(value_a_ * value_b_);
}

void CalculatorServiceTask::TaskDivide::Solve() {
#ifdef TESTING_HARD_TASKS_MODEL
  std::this_thread::sleep_for(std::chrono::milliseconds(HARD_TASK_TIME));
#endif
  if (value_b_ == 0) {
    std::cerr << "In TaskDivide::solve(): divide by 0\n";
    return;
  }
  reply_(value_a_ / value_b_);
}
