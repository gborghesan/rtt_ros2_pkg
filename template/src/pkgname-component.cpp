#include "@(package)-component.hpp"
#include <rtt/Component.hpp>
#include <iostream>


@(package)_component::@(package)_component(std::string const& name) : TaskContext(name){
  std::cout << "@(package)_component constructed !" <<std::endl;
  addPort("test_port", test_port).doc("This is a test port");
}

bool @(package)_component::configureHook(){
  std::cout << "@(package)_component configured !" <<std::endl;
  return true;
}

bool @(package)_component::startHook(){
  std::cout << "@(package)_component started !" <<std::endl;
  i.data=0;
  return true;
}

void @(package)_component::updateHook(){
  std::cout << "@(package)_component executes updateHook !" <<std::endl;
  test_port.write(i);
  i.data++;
}

void @(package)_component::stopHook() {
  std::cout << "@(package)_component executes stopping !" <<std::endl;
}

void @(package)_component::cleanupHook() {
  std::cout << "@(package)_component cleaning up !" <<std::endl;
}

/*
 * Using this macro, only one component may live
 * in one library *and* you may *not* link this library
 * with another component library. Use
 * ORO_CREATE_COMPONENT_TYPE()
 * ORO_LIST_COMPONENT_TYPE(@(package)_component)
 * In case you want to link with another library that
 * already contains components.
 *
 * If you have put your component class
 * in a namespace, don't forget to add it here too:
 */
ORO_CREATE_COMPONENT(@(package)_component)
