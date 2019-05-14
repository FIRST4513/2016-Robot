// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "LiftToBottmCmd.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

LiftToBottmCmd::LiftToBottmCmd(): Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::liftSys.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void LiftToBottmCmd::Initialize() {
	SetTimeout(10);						// we should hit bottom within 10 seconds
	Robot::liftSys->DriveLiftMtr(Robot::liftSys->kLiftSpeedFast * -1);
}

// Called repeatedly when this Command is scheduled to run
void LiftToBottmCmd::Execute() {
	Robot::liftSys->DisplaySmartdashValues();
}

// Make this return true when this Command no longer needs to run execute()
bool LiftToBottmCmd::IsFinished() {
	if (IsTimedOut()) return true;
	if (Robot::liftSys->GetLowerLmtSw() == true) return true;
    return false;
}

// Called once after isFinished returns true
void LiftToBottmCmd::End() {
	Robot::liftSys->LiftMtrStop();
	Robot::liftSys->DisplaySmartdashValues();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftToBottmCmd::Interrupted() {
	End();
}
