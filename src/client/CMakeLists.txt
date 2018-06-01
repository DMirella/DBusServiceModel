cmake_minimum_required(VERSION 2.6)
project(Client)

set(CALCULATOR_SERVICE_SRCGEN_PATH   /home/dima/work/DBusServiceModel/src-gen)
set(SRCGEN_V1_COM_LUXOFT_PATH        ${CALCULATOR_SERVICE_SRCGEN_PATH}/v1/com/luxoft/calculatorservice)
set(SRCGEN_V1_COM_LUXOFT_PATH_CPPS   ${CALCULATOR_SERVICE_SRCGEN_PATH}/v1/com/luxoft/calculatorservice)
set(SRCGEN_V1_COM_LUXOFT_CLIENT_CPPS ${SRCGEN_V1_COM_LUXOFT_PATH}/CalculatorServiceDBusDeployment.cpp
		      		     ${SRCGEN_V1_COM_LUXOFT_PATH}/CalculatorServiceDBusProxy.cpp)
file(GLOB CC_FILES *.cc)

include(~/work/DBusServiceModel/src/cmake_includes/DBusSets.txt)
include_directories(${CALCULATOR_SERVICE_SRCGEN_PATH}
	 	    ${DBUS_INCLUDE_DIRECTORIES})
link_directories(${DBUS_LINK_DIRECTORIES})


add_executable(Client ${CC_FILES} ${SRCGEN_V1_COM_LUXOFT_CLIENT_CPPS})


target_link_libraries(Client ${DBUS_LIBS})
