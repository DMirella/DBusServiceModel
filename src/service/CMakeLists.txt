cmake_minimum_required(VERSION 2.6)
project(CalculatorService)

set(CALCULATOR_SERVICE_SRCGEN      ~/work/DBusServiceModel/src-gen)
set(SRCGEN_V1_COM_LUXOFT_PATH      ${CALCULATOR_SERVICE_SRCGEN}/v1/com/luxoft/calculatorservice)
set(CALCULATOR_SERVICE_SRCGEN_CCPS ${SRCGEN_V1_COM_LUXOFT_PATH}/CalculatorServiceDBusDeployment.cpp
				   ${SRCGEN_V1_COM_LUXOFT_PATH}/CalculatorServiceDBusStubAdapter.cpp
				   ${SRCGEN_V1_COM_LUXOFT_PATH}/CalculatorServiceStubDefault.cpp)
file(GLOB CC_FILES *.cc)

include(~/work/DBusServiceModel/src/cmake_includes/DBusSets.txt)

include_directories(include/
		    ${CALCULATOR_SERVICE_SRCGEN}
		    ${DBUS_INCLUDE_DIRECTORIES})
link_directories(${DBUS_LINK_DIRECTORIES})

add_executable(CalculatorService ${CC_FILES} ${CALCULATOR_SERVICE_SRCGEN_CCPS})
target_link_libraries(CalculatorService pthread ${DBUS_LIBS})
