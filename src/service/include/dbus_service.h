#ifndef DBUS_SERVICE_HPP_
#define DBUS_SERVICE_HPP_

#include <CommonAPI/CommonAPI.hpp>
#include <thread>
#include "service.h"

namespace Service{
namespace DBusService{

/* Standart CommonAPI-DBus service interface */
template<typename ServiceType_>
class DBusService : public Service {
 using ServiceTypeSharedPtr = std::shared_ptr<ServiceType_>;

 public:
  DBusService(std::string name, ServiceTypeSharedPtr service)
    : name_(std::move(name)), service_(std::move(service)) {
    runtime_ = CommonAPI::Runtime::get();
    runtime_->registerService("", name_, service_);
  }
  virtual void startService() override { 
    service_thread_ = std::make_unique<std::thread>(&DBusService::doServiceThread, this);
  }
  /* Needs for security, can be overrided in future */
  DBusService(const DBusService&) = delete;  
 protected:
  virtual void doServiceThread() = 0;
 private:
  std::string name_;
  ServiceTypeSharedPtr service_;
  std::shared_ptr<CommonAPI::Runtime> runtime_;  
  std::unique_ptr<std::thread> service_thread_;
};


}  // namespace DBusService
}  // namespace Service

#endif  // DBUS_SERVICE_HPP_
