cmake_minimum_required(VERSION 2.6)
project(Client)

SET(DEFAULT_SEND_TIMEOUT "10000" CACHE STRING "default send timeout")
message(STATUS "DEFAULT_SEND_TIMEOUT is set to value: ${DEFAULT_SEND_TIMEOUT} ms")

include_directories(~/work/DBusServiceModel/src-gen
		    ~/work/capicxx-core-runtime/include
		    ~/work/capicxx-dbus-runtime/include
		    ~/work/dbus-1.10.10)

link_directories(/home/dima/work/capicxx-core-runtime/build
 		 /home/dima/work/capicxx-dbus-runtime/build
		 /home/dima/work/dbus-1.10.10/dbus/.libs)

set(V1_COM_LUXOFT_PATH /home/dima/work/DBusServiceModel/src-gen/v1/com/luxoft/calculatorservice)



add_executable(Client Client.cpp
		      ${V1_COM_LUXOFT_PATH}/CalculatorServiceDBusDeployment.cpp
		      ${V1_COM_LUXOFT_PATH}/CalculatorServiceDBusProxy.cpp)


target_link_libraries(Client CommonAPI CommonAPI-DBus dbus-1)
