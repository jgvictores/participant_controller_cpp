// Basic participant controller.

#include <webots/Robot.hpp>
#include <webots/Device.hpp>
#include <webots/Motor.hpp>
#include <webots/Lidar.hpp>
#include <webots/GPS.hpp>

#include <iostream>
#include <limits>

int main(int argc, char **argv)
{
    // Initialize the robot
    webots::Robot *robot = new webots::Robot();
    int timestep = int(robot->getBasicTimeStep());

    // Initialize motors
    webots::Motor* motor_left = robot->getMotor("wheel_left_joint");
    webots::Motor* motor_right = robot->getMotor("wheel_right_joint");
    webots::Lidar* lidar = robot->getLidar("Hokuyo URG-04LX-UG01");
    webots::GPS* position = robot->getGPS("gps");

    motor_left->setPosition(std::numeric_limits<double>::infinity());
    motor_right->setPosition(std::numeric_limits<double>::infinity());

    // Main loop:
    // - perform simulation steps until Webots is stopping the controller
    while (robot->step(timestep) != -1)
    {
    }

    // Exit cleanup code here.
    delete robot;
    return 0;
}