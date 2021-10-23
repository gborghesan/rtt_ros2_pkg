from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory


def generate_launch_description():
    return LaunchDescription([

        Node(
            executable=['rttlua'],
            arguments=['-i', get_package_share_directory('@(package)')+"/scripts/deploy.lua"],
            output='screen',
            emulate_tty=True
        )
    ])

if __name__ == '__main__':
    from launch import LaunchService
    ls = LaunchService()
    ls.include_launch_description(generate_launch_description())
    ls.run()


