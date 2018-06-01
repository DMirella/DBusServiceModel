#ifndef DBUSSERVICEMODEL_SRC_SERVICE_INCLUDE_TASK_H_
#define DBUSSERVICEMODEL_SRC_SERVICE_INCLUDE_TASK_H_

namespace DBusServiceModel {
class Task {
 public:
  virtual ~Task() {}
  //In this function you must write your solve task logic
  virtual void Solve() = 0;
};
}  // namespace DBusServiceModel

#endif  // DBUSSERVICEMODEL_SRC_SERVICE_INCLUDE_TASK_H_
