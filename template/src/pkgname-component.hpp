#ifndef OROCOS_@(package)_COMPONENT_HPP
#define OROCOS_@(package)_COMPONENT_HPP

#include <rtt/RTT.hpp>
#include <std_msgs/typekit/Types.hpp>

class @(package)_component : public RTT::TaskContext{
  public:
    @(package)_component(std::string const& name);
    bool configureHook();
    bool startHook();
    void updateHook();
    void stopHook();
    void cleanupHook();
  private:
  	RTT::OutputPort<std_msgs::msg::Int32> test_port;
  	std_msgs::msg::Int32 i;
};
#endif
