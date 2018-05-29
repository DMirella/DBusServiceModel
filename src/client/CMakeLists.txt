cmake_minimum_required(VERSION 2.6)
project(Client)

include(../cmake_includes/DBusSets.txt)

include_directories(~/work/DBusServiceModel/src-gen
	 	    ${DBUS_INCLUDE_DIRECTORIES})

link_directories(${DBUS_LINK_DIRECTORIES})

set(V1_COM_LUXOFT_PATH /home/dima/work/DBusServiceModel/src-gen/v1/com/luxoft/calculatorservice)



add_executable(Client main.cpp
		      ClientCalculatorDBusService.cpp
		      ${V1_COM_LUXOFT_PATH}/CalculatorServiceDBusDeployment.cpp
		      ${V1_COM_LUXOFT_PATH}/CalculatorServiceDBusProxy.cpp)


target_link_libraries(Client ${DBUS_LIBS})
