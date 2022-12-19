# RTT ROS2 Create Package

This package is meant to provide the functionality of creating an orocos package ready to be compiled with the colcon-ROS2 build system.

## usage
The only command that can be invoked is `orocreate-colcon-pkg`.

the basic use is 
```
ros2 run rtt_ros2_pkg orocreate-colcon-pkg pkg_name
```

Please refer to the help for more info


```
ros2 run rtt_ros2_pkg orocreate-colcon-pkg --help
```


To generate a package named `test_pkg` with a sample compenent and the minimal deployment files, in a `src` folder, 
it suffices to execute the following in the root of a colcon workspace
```bash
ros2 run rtt_ros2_pkg orocreate-colcon-pkg --create deploy component  -d  src test_pkg
colcon build--symlink-install
source install/local_setup.bash
```
To deploy, the lua file can be invoked direclty (and interactive shell being available)
```bash
rttlua -i `ros2 pkg prefix test_pkg`/share/test_pkg/scripts/deploy.lua
```
OR via the generated launch file
```bash
ros2 launch test_pkg example.launch.py
