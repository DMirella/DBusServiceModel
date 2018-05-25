#ifndef DBUSSERVICE_H_
#define DBUSSERVICE_H_

#include "Service.hpp"

#include <CommonAPI/CommonAPI.hpp>
#include <thread>

template<typename ServiceType_>
class DBusService : public Service{

 public:
  DBusService(std::string name, std::unique_ptr<ServiceType_> service)
    : name_(std::move(name)), service_(std::move(service)) {
    runtime_ = CommonAPI::Runtime::get();
    runtime_->registerService("", name_, service_);
  }

  virtual void startService() override { 
    service_thread_ = std::make_unique<std::thread>(&DBusService::doServiceThread, this);
  }
  
 protected:
  virtual void doServiceThread() = 0;

 private:
  std::shared_ptr<ServiceType_> service_;
  std::shared_ptr<CommonAPI::Runtime> runtime_;
  
  std::string name_;
  std::unique_ptr<std::thread> service_thread_;
};

#endif  //DBUSSERVICE_H_
