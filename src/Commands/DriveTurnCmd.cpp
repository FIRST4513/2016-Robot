// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "DriveTurnCmd.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

DriveTurnCmd::DriveTurnCmd(double lftSpeed, double rtSpeed, double angle, double timeOut, double mode): Command() {
    m_lftSpeed = lftSpeed;
    m_rtSpeed = rtSpeed;
    m_angle = angle;
    m_timeOut = timeOut;
    m_mode = mode;
        // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::drivetrain.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void DriveTurnCmd::Initialize() {
	SetTimeout(m_timeOut);
	Robot::drivetrain->ResetEncoders();
	Robot::drivetrain->SetFirstTimeFlag(0);			// set flag to zero for gyro correction
	Robot::drivetrain->GyroReset();					// Reset gyro to heading zero
	beginHeading = Robot::drivetrain->GetHeading(0);
	turnFlag = 0;		// 1 = straight, 2=Pt.Turn, 3=Swing Turn, 4 Arc Turn

	if (m_lftSpeed == m_rtSpeed) turnFlag = 1;					// Straight
	if (m_lftSpeed == (m_rtSpeed * -1)) turnFlag = 2;			// Point Turn
	if ((m_lftSpeed == 0) || (m_rtSpeed == 0)) turnFlag = 3;	// Swing Turn
	else turnFlag = 4;											// Arc Turn

	if ((m_lftSpeed > m_rtSpeed) && (m_angle < 0)) m_angle = m_angle * (-1);	// turning right angle should be positive
	if ((m_lftSpeed < m_rtSpeed) && (m_angle > 0)) m_angle = m_angle * (-1);	// turning left angle should be negative

	Robot::drivetrain->ZeroBeginEndValues();
	Robot::drivetrain->PostBeginValues();
}

// Called repeatedly when this Command is scheduled to run
void DriveTurnCmd::Execute() {
	Robot::drivetrain->TankDrive(m_lftSpeed, m_rtSpeed);

	Robot::drivetrain->PostCurrValues();
	Robot::drivetrain->DisplaySmartdashValues();
}

// Make this return true when this Command no longer needs to run execute()
bool DriveTurnCmd::IsFinished() {
	if (IsTimedOut()) return true;

	if ((m_angle > 0) && (Robot::drivetrain->GetHeading(0) >= m_angle)) return true; // We have made it
	if ((m_angle < 0) && (Robot::drivetrain->GetHeading(0) <= m_angle)) return true; // We have made it
    return false;
}

// Called once after isFinished returns true
void DriveTurnCmd::End() {
	Robot::drivetrain->Stop();

	Robot::drivetrain->PostEndValues();
	Robot::drivetrain->DisplaySmartdashValues();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveTurnCmd::Interrupted() {
	End();
}