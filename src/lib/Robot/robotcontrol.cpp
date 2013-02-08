#include "robotcontrol.h"

/*
 * Constructor
 *
 * dev - file of usb serial device
 */
robot::RobotControl::RobotControl(std::string dev) {

    device = dev;
}

/*
 * Try to open Serial port based on USB
 *
 * Send to robot and return true if file successfuly opened.
 * Otherwise return false.
 */
bool robot::RobotControl::robotConnect() {

    serial.open(device.c_str());
    if (serial.is_open()) {

        serial.flush();
        serial << 'S';
        serial.flush();

        return true;
    }
    else {

        return false;
    }
}

/*
 * Move forward for robot with differential kinematics shceme
 *
 * lSpeed - speed of left wheel [0, 255]
 * rSpeed - speed of right wheel [0, 255]
 */

bool robot::RobotControl::move(int lSpeed, int rSpeed) {

    if (!serial.is_open()) {
        return false;
    }

    std::stringstream save_file;
    command << "D," << lSpeed << "," << rSpeed << std::endl;

    serial << command.str();
    command.flush();
    serial.flush();

    return true;
}

bool robot::RobotControl::stop() {

    if (!serial.is_open()) {
        return false;
    }

    serial.flush();
    serial << 'S';
    serial.flush();

    return true;
}
