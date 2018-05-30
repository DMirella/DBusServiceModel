# DBusServiceModel
This is review of code files


Let's start with the service-side(src/service)
----------------------------------------------------------------------------------
include/Task.hpp - contains the Task class, which is a class of the job,
with a single Task::solve() method that overrides all other task classes.

include/Service.hpp - contains the Service class, which present the service 
interface. All services must be starts by Service::startService() method.

include/DBusService.hpp - contains DBusService class implemented from Service 
class. It need to recieve a tamplate type, which must be a dbus proxy class. 
This class realize the service interface by using commonapi-dbus methods. 
All concrate services must be implemented from it. All class which 
implemented this class, must override DBusService::doServiceThread() method.

include/SyncQueue.hpp - contains SynQueue class, which realize the queue 
interface with synchronization capability, by using std::mutex.


CalculatorServiceStubImpl.hpp/CalculatorServiceStubImpl.cpp - implements from 
CalculatorServiceStubDefault, and realize the server methods. This is standart moves 
for dbus-using applications

CalculatorServiceTasks.hpp/CalculatorServiceTasks.cpp - contains the Task-classes, 
which realize the CalculatorService tasks, by implements from Task class, 
and override Task::solve() method.

DBusCalculatorService.hpp/DBusCalculatorService.cpp - contains DBusCalculatorService 
class implemented from DBusService class, and override DBusService::doServiceThread() method.

TaskManager.hpp - contains TaskManager and TaskSolver classes. TaskManager - 
class manager which create a TaskSolver and SyncQueue objects, and managed them.


main.cpp - demonstrate possible use of created API.


Now, consider the client side(src/client).
-------------------------------------------------------------------------------------
Unfortunately, I did not manage to 
make such a generalized API for the client's side. Everything rests on the problem 
of that it is impossible to write a template-virtual function. In fact, I can try to make 
generalized API (at least using lines to identify the methods), but it 
still will not turn out so beautiful as on the service side, so I decided to leave it as it is.


ClientCalculatorDBusService.hpp/ClientCalculatorDBusService.cpp - 
contains ClientCalculatorDBusService class which realize simple client-side interface of service.
It works like a proxy, which recieves client queries and directs their to dbus service.

main.cpp - demonstrate possible use of created API.



Also cmake_includes contain one include file, which contains cmake-sets for using commonapi-dbus libraries.


Thanks, for attention.
