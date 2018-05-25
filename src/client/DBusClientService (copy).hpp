#ifndef DBUSCLIENTSERVICE_H_
#define DBUSCLIENTSERVICE_H_

#include <unistd.h>
#include <thread>
#include <CommonAPI/CommonAPI.hpp>
#include <CommonAPI/Proxy.hpp>
#include <string>

template<typename ServiceProxyType_>
class DBusClient{
 public:
  DBusClient(std::shared_ptr<ServiceProxyType_> proxy) : proxy_(proxy) {
    runtime_ = CommonAPI::Runtime::get();
  }
  virtual void startWorkWithService() override {
    client_thread_ = std::make_unique<std::thread>(&DBusClient::doClientThread, this);
  }
 protected:
  virtual void clientThreadLogic() = 0;

 private:
  void doClientThread() {
    while(!service_proxy_->isAvailable())std::this_thread::sleep_for(std::chrono:seconds(5));
    clientThreadLogic();
  }

  std::string name_service_;

  std::unique_ptr<std::thread> client_thread_;
  std::shared_ptr<CommonAPI::Runtime> runtime_;
  std::shared_ptr<ServiceProxyType_> service_proxy_;
};


#endif  //DBUSCLIENTSERVICE_H_
