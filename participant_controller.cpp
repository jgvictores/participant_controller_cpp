// Basic participant controller.

#include <webots/Robot.hpp>
#include <webots/Device.hpp>
#include <webots/Motor.hpp>

#include <iostream>

int main(int argc, char **argv)
{
    // Initialize the robot
    webots::Robot *robot = new webots::Robot();
    timestep = int(robot.getBasicTimeStep());

    // Initialize motors
    webots::Motor* motor_left = robot->getMotor('wheel_left_joint');
    webots::Motor* motor_right = robot->getMotor('wheel_right_joint');
    webots::Motor* lidar = robot->getDevice('Hokuyo URG-04LX-UG01');
    webots::Motor* position = robot->getDevice('gps');

    // Main loop:
    // - perform simulation steps until Webots is stopping the controller
    while (robot->step(timeStep) != -1)
    {
        motor_left->setPosition(45.0*3.14/180.0);
    }

    // Exit cleanup code here.
    delete robot;
    return 0;
}