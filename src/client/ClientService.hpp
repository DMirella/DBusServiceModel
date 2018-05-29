#ifndef CLIENT_SERVICE_HPP_
#define CLIENT_SERVICE_HPP_

#include <memory>

#include "ServiceMethodCaller.hpp"

class ClientService {
 public:
  template<class ...Args>
  void callServiceMethod(std::shared<CallServiceMethodType> caller, Args&&... args) {
    caller->call(std::forward<Args>(args)...);
  }
};


#endif  // CLIENT_SERVICE_HPP_
