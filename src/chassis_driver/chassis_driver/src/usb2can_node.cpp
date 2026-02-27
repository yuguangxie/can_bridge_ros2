#include "usb2can_core.h"
#include <rclcpp/rclcpp.hpp>

// 节点主入口：仅负责生命周期控制，具体业务逻辑由 CAN_app 实现。
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<USB2CAN::CAN_app>();
    // run() 内部根据参数选择 USB2CAN 或 EthCAN_UDP 模式。
    node->run();

    rclcpp::shutdown();
    return 0;
}
