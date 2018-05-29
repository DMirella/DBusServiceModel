#ifndef SERVICE_METHOD_CALLER_HPP_
#define SERVICE_METHOD_CALLER_HPP_

#include <memory>

class CallServiceMethodType {
 public:
  template<class ...Args>
  virtual void call(Args&& ...args) const = 0;
};

class ServiceMethodCaller {
 public:

  template<typename SyncFunctionType_>
  class Sync : public CallServiceMethodType {
   public:
    Sync(std::function<SyncFunctionType_> service_method) : service_method_(service_method) { }
    virtual void call(Args&& ...args) const override {
      service_method_(std::forward<Args>(args)...);
    }
   private:
    std::function<SyncFunctionType_> service_method_;
  }

  template<typename SyncFunctionType_>
  class Async : public CallServiceMethodType{
   public:
    Async(std::function<SyncFunctionType_> service_method) : service_method_(service_method) { }
    virtual void call(Args&& ...args) const override {
      service_method_(std::forward<Args>(args)...);
    }
   private:
    std::function<SyncFunctionType_> service_method_;
  }
};


#endif  // SERVICE_METHOD_CALLER_HPP_
