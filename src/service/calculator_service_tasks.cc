#include "calculator_service_tasks.h"

#include <chrono>
#include <iostream>
#include <thread>

namespace DBusServiceModel {
namespace {
const int kInfinity = 2010101010;
const auto kTestHardTaskSleepTimeMs = std::chrono::milliseconds(200);
}

void TaskSum::Solve() {
#ifdef TESTING_HARD_TASKS_MODEL
  std::this_thread::sleep_for(kTestHardTaskSleepTimeMs);
#endif
  reply_(value_a_ + value_b_);
}

void TaskDeduct::Solve() {
#ifdef TESTING_HARD_TASKS_MODEL
  std::this_thread::sleep_for(kTestHardTaskSleepTimeMs);
#endif
  reply_(value_a_ - value_b_);
}

void TaskMultiply::Solve() {
#ifdef TESTING_HARD_TASKS_MODEL
  std::this_thread::sleep_for(kTestHardTaskSleepTimeMs);
#endif
  reply_(value_a_ * value_b_);
}

void TaskDivide::Solve() {
#ifdef TESTING_HARD_TASKS_MODEL
  std::this_thread::sleep_for(kTestHardTaskSleepTimeMs);
#endif
  if (value_b_ == 0) {
    std::cerr << "In TaskDivide::solve(): divide by 0\n";
    return;
  }
  reply_(value_a_ / value_b_);
}
}  // namespace DBusServiceModel
