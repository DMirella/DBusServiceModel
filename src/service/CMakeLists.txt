cmake_minimum_required(VERSION 2.6)
project(CalculatorService)

include(../cmake_includes/DBusSets.txt)


include_directories(include/
		    ~/work/DBusServiceModel/src-gen
		    ${DBUS_INCLUDE_DIRECTORIES})

link_directories(${DBUS_LINK_DIRECTORIES})

set(V1_COM_LUXOFT_PATH /home/dima/work/DBusServiceModel/src-gen/v1/com/luxoft/calculatorservice)


add_executable(CalculatorService main.cpp
				 CalculatorServiceStubImpl.cpp
				 CalculatorServiceTasks.cpp
				 DBusCalculatorService.cpp
				 ${V1_COM_LUXOFT_PATH}/CalculatorServiceDBusDeployment.cpp
				 ${V1_COM_LUXOFT_PATH}/CalculatorServiceDBusStubAdapter.cpp
				 ${V1_COM_LUXOFT_PATH}/CalculatorServiceStubDefault.cpp)


target_link_libraries(CalculatorService pthread ${DBUS_LIBS})
