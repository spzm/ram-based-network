#ifndef ROBOTCONTROL_H
#define ROBOTCONTROL_H

#include <string>
#include <fstream>
#include <sstream>

namespace robot {

/*
 * Class for control robot via Serial port
 */

class RobotControl
{
private:
    std::string device;
    std::ofstream serial;
    std::stringstream command;

public:
    RobotControl(std::string dev = "/dev/ttyUSB0");
    bool robotConnect();
    bool move(int lSpeed, int rSpeed);
    bool stop();
};

}

#endif // ROBOTCONTROL_H
