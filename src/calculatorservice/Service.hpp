#ifndef SERVICE_H_
#define SERVICE_H_

#include <iostream>

class Service {
 public:
  Service() {  }
  virtual void startService() = 0;
};

#endif  //SERVICE_H_
