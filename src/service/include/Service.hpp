#ifndef SERVICE_HPP_
#define SERVICE_HPP_

#include <iostream>

namespace Service{
class Service {
 public:
  Service() {}
  virtual void startService() = 0;
};
}  // namespace Service

#endif  //SERVICE_HPP_
