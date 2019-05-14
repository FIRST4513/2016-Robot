// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	std::shared_ptr<Joystick> shooterJoystick;
	std::shared_ptr<JoystickButton> liftStopBtn2;
	std::shared_ptr<JoystickButton> liftByJoystickBtn2;
	std::shared_ptr<JoystickButton> autoAimBtn;
	std::shared_ptr<JoystickButton> autoFireBtn;
	std::shared_ptr<JoystickButton> toggleDisplayBtn;
	std::shared_ptr<JoystickButton> ledOffBTN;
	std::shared_ptr<JoystickButton> ledOnBtn;
	std::shared_ptr<JoystickButton> shooterStopMotorsBtn;
	std::shared_ptr<JoystickButton> shooterSpinUpBtn;
	std::shared_ptr<JoystickButton> shooterFireHighGoalBtn;
	std::shared_ptr<JoystickButton> shooterFireLowGoalBtn;
	std::shared_ptr<JoystickButton> shooterRetractionBtn;
	std::shared_ptr<JoystickButton> liftStopBtn;
	std::shared_ptr<JoystickButton> liftDriveStopBtn;
	std::shared_ptr<JoystickButton> liftByJoystickBtn;
	std::shared_ptr<JoystickButton> shooterStartDefaultBtn;
	std::shared_ptr<Joystick> driverJoystick;
	std::shared_ptr<JoystickButton> liftTo10Btn;
	std::shared_ptr<JoystickButton> driverLiftStopBtn;
	std::shared_ptr<JoystickButton> driverLiftByJoystickBtn;
	std::shared_ptr<JoystickButton> resetHdgEncBtn;
	std::shared_ptr<JoystickButton> shooterOffBtn;
	std::shared_ptr<JoystickButton> liftToTopBtn;
	std::shared_ptr<JoystickButton> liftToBottomBth;
	std::shared_ptr<JoystickButton> retractAndHoldBallBtn;
	std::shared_ptr<JoystickButton> driveStopBtn;
	std::shared_ptr<JoystickButton> startDefaultCmdBtn;
	std::shared_ptr<JoystickButton> driveByJostickBtn;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
public:
	OI();

	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PROTOTYPES

	std::shared_ptr<Joystick> getDriverJoystick();
	std::shared_ptr<Joystick> getShooterJoystick();

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PROTOTYPES
};

#endif
