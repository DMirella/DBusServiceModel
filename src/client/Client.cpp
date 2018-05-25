#include <iostream>
#include <string>
#include <unistd.h>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/com/luxoft/calculatorservice/CalculatorServiceProxy.hpp>
  
using namespace v1::com::luxoft::calculatorservice;


void recv_rev(CommonAPI::CallStatus callstatus, const int &out){
	std::cout << "Thank you for result, server: " << out << std::endl;
}

int main(){
	std::shared_ptr<CommonAPI::Runtime> runtime = CommonAPI::Runtime::get();
	std::shared_ptr<CalculatorServiceProxy<>> proxy 
		= runtime->buildProxy<CalculatorServiceProxy>("", "CalculatorService");
	
	std::cout << "Client available.\n";
        while(!proxy->isAvailable())usleep(10);
	
	while(1){
		proxy->divideAsync(6, 2, recv_rev);
		usleep(19000);
	}
	
	return 0;
}
