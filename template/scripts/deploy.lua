require "rttlib"
require "rttros"

rttlib.color = true



tc=rtt.getTC()
if tc:getName() == "lua" then
  depl=tc:getPeer("Deployer")
elseif tc:getName() == "Deployer" then
  depl=tc
end
depl:import("rtt_ros2")
ros=rtt.provides("ros")

ros:import("@package")

ros:import("rtt_ros2_std_msgs")

-- to create a ros node
rtt.provides("ros"):create_named_node_with_namespace("Main_node","@(package)_app")


-- you can use this directory to load files (e.g. cpf or lua files) that have been installed
@(package)_dir = rtt.provides("ros"):find("@package")

depl:loadComponent("cmp", "@(package)_component")

cmp = depl:getPeer("cmp")
cmp:setPeriod(1)

depl:stream("cmp.test_port", ros:topic("/test_topic",false)) 

cmp:configure()
cmp:start()
