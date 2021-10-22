cmake_minimum_required(VERSION 3.5)
project(@(package))

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rtt_ros2 REQUIRED)
# find_package(rtt_ros2_params REQUIRED)
find_package(rtt_ros2_node REQUIRED) # Required ?
find_package(rtt_ros2_std_msgs REQUIRED)

@[if component]@
orocos_component(@package-component
  src/@package-component.cpp
)
ament_target_dependencies(@package-component
  rclcpp
  # rtt_ros2_params
)
target_link_libraries(@package-component
  rtt_ros2_std_msgs::rtt_std_msgs_typekit
)
@[end if]@


## to install some header or application file in the share folder
#install(DIRECTORY include/
#  DESTINATION include
#)

install(DIRECTORY scripts
  DESTINATION share/@(package)/
)


# rtt_ros2_export_plugin_depend(rtt_ros2_params)
 rtt_ros2_export_plugin_depend(rtt_ros2_std_msgs)

# must be called *after* the targets to check exported libraries etc.
ament_package()

# orocos_generate_package() is deprecated for ROS 2.
# Prefer cmake target export and import instead, in combination with
# ament_export_interfaces() or ament_export_targets() when building with
# ament_cmake.
orocos_generate_package(
INCLUDE_DIRS src 
	DEPENDS_TARGETS
		rtt_ros2
		rtt_ros2_std_msgs
		
)
