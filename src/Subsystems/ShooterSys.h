// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef SHOOTERSYS_H
#define SHOOTERSYS_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class ShooterSys: public Subsystem {
private:
	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	std::shared_ptr<SpeedController> shooterFrontMtr;
	std::shared_ptr<SpeedController> shooterRearMtr;
	std::shared_ptr<DigitalInput> shooterContactSw;
	std::shared_ptr<Relay> captureLeftSpike;
	std::shared_ptr<Relay> captureRightSpike;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
public:
	const bool LIMITSWITCHPRESSED = false;
	const float kHoldBallSpeed = -0.2;
	const float kRetractBallFrontMtrSpeed = -0.3;
	const float kRetractBallRearMtrSpeed = -0.3;
	const float kPushBallIntoShooterSpeed = 0.5;
	const float kShootLowGoalSpeed = 0.3;
	const float kShootHiGoalSpeed = 1.0;

	float shooterSpeed;
	bool speedFlag;

	ShooterSys();
	void InitDefaultCommand();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

	void DriveFrontMtr(float speed);
	void DriveRearMtr(float speed);

	void StopMtrs();
	void StopFrontMtr();
	void StopRearMtr();

	void CaptureMotorsRetract();
	void CaptureMotorsStop();
	void HoldBall();			// Front Motor Stop, Back Motor Hold speed
	void CaptureBall();			// Front & Rear motor at retract speed or rear motor at hold speed ??

	void SpinUpLowGoal();		// Front motor at Low goal speed
	void SpinUpHighGoal();		// Front motor at High goal speed

	void SetShooterSpeed(float speed);
	float GetShooterSpeed();
	void SetSpeedFlag(bool value);
	bool GetSpeedFlag();


	bool GetRearContactLmtSw();		// Returns true if pressed

	void DisplaySmartdashValues();
};

#endif