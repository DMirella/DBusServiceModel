#include "CalculatorServiceStubImpl.hpp"

void CalculatorServiceStubImpl::sum(const std::shared_ptr<CommonAPI::ClientId> _client, int32_t _valueA, int32_t _valueB, sumReply_t _reply) {
	_reply(1);
}

void CalculatorServiceStubImpl::deduct(const std::shared_ptr<CommonAPI::ClientId> _client, int32_t _valueA, int32_t _valueB, deductReply_t _reply) {
	
	_reply(1);
}

void CalculatorServiceStubImpl::multiply(const std::shared_ptr<CommonAPI::ClientId> _client, int32_t _valueA, int32_t _valueB, multiplyReply_t _reply) {
	
	_reply(1);
}

void CalculatorServiceStubImpl::divide(const std::shared_ptr<CommonAPI::ClientId> _client, int32_t _valueA, int32_t _valueB, divideReply_t _reply) {
	
	_reply(1);
}

