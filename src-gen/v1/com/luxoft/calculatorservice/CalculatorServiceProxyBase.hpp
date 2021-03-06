/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.core 3.1.12.v201801251447.
* Used org.franca.core 0.9.1.201412191134.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#ifndef V1_COM_LUXOFT_CALCULATORSERVICE_Calculator_Service_PROXY_BASE_HPP_
#define V1_COM_LUXOFT_CALCULATORSERVICE_Calculator_Service_PROXY_BASE_HPP_

#include <v1/com/luxoft/calculatorservice/CalculatorService.hpp>



#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#endif

#include <vector>

#include <CommonAPI/Proxy.hpp>
#include <functional>
#include <future>

#undef COMMONAPI_INTERNAL_COMPILATION

namespace v1 {
namespace com {
namespace luxoft {
namespace calculatorservice {

class CalculatorServiceProxyBase
    : virtual public CommonAPI::Proxy {
public:

    typedef std::function<void(const CommonAPI::CallStatus&, const int32_t&)> SumAsyncCallback;
    typedef std::function<void(const CommonAPI::CallStatus&, const int32_t&)> DeductAsyncCallback;
    typedef std::function<void(const CommonAPI::CallStatus&, const int32_t&)> MultiplyAsyncCallback;
    typedef std::function<void(const CommonAPI::CallStatus&, const int32_t&)> DivideAsyncCallback;



    virtual void sum(const int32_t &_valueA, const int32_t &_valueB, CommonAPI::CallStatus &_internalCallStatus, int32_t &_result, const CommonAPI::CallInfo *_info = nullptr) = 0;
    virtual std::future<CommonAPI::CallStatus> sumAsync(const int32_t &_valueA, const int32_t &_valueB, SumAsyncCallback _callback = nullptr, const CommonAPI::CallInfo *_info = nullptr) = 0;
    virtual void deduct(const int32_t &_valueA, const int32_t &_valueB, CommonAPI::CallStatus &_internalCallStatus, int32_t &_result, const CommonAPI::CallInfo *_info = nullptr) = 0;
    virtual std::future<CommonAPI::CallStatus> deductAsync(const int32_t &_valueA, const int32_t &_valueB, DeductAsyncCallback _callback = nullptr, const CommonAPI::CallInfo *_info = nullptr) = 0;
    virtual void multiply(const int32_t &_valueA, const int32_t &_valueB, CommonAPI::CallStatus &_internalCallStatus, int32_t &_result, const CommonAPI::CallInfo *_info = nullptr) = 0;
    virtual std::future<CommonAPI::CallStatus> multiplyAsync(const int32_t &_valueA, const int32_t &_valueB, MultiplyAsyncCallback _callback = nullptr, const CommonAPI::CallInfo *_info = nullptr) = 0;
    virtual void divide(const int32_t &_valueA, const int32_t &_valueB, CommonAPI::CallStatus &_internalCallStatus, int32_t &_result, const CommonAPI::CallInfo *_info = nullptr) = 0;
    virtual std::future<CommonAPI::CallStatus> divideAsync(const int32_t &_valueA, const int32_t &_valueB, DivideAsyncCallback _callback = nullptr, const CommonAPI::CallInfo *_info = nullptr) = 0;
};

} // namespace calculatorservice
} // namespace luxoft
} // namespace com
} // namespace v1


// Compatibility
namespace v1_0 = v1;

#endif // V1_COM_LUXOFT_CALCULATORSERVICE_Calculator_Service_PROXY_BASE_HPP_
