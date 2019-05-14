// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.



#include "AutoShootHighGoalCmdGrp.h"
#include "AutoSetupShootHighGoalCmdGrp.h"
#include "DrivePointTurnCmd.h"
#include "LiftToAngleCmd.h"
#include "ProccessVisionData.h"
#include "DelayCmd.h"
#include "AutoAimCmdGrp.h"
#include "ShooterFireCmdGrp.h"
#include "ShooterSpinUpCmd.h"



// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

AutoShootHighGoalCmdGrp::AutoShootHighGoalCmdGrp() {
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR
     // Add Commands here:
    // e.g. AddSequential(new Command1());
    //      AddSequential(new Command2());
    // these will run in order.

    // To run multiple commands at the same time,
    // use AddParallel()
    // e.g. AddParallel(new Command1());
    //      AddSequential(new Command2());
    // Command1 and Command2 will run in parallel.

    // A command group will require all of the subsystems that each member
    // would require.
    // e.g. if Command1 requires chassis, and Command2 requires arm,
    // a CommandGroup containing them would require both the chassis and the
    // arm.
              // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=COMMAND_DECLARATIONS

	AddSequential(new AutoSetupShootHighGoalCmdGrp);

	std::cout << "this is a test" << std::endl;

	AddParallel(new ProccessVisionData()); 				// 75.5 inches 4 inches short because of stopping overrun
	AddSequential(new DelayCmd(0.5)); 					// a 0.5 second delay command here to collect visual data !!!

	AddSequential(new AutoAimCmdGrp()); 					// Pan and tilt for firing based on vision data
	//AddSequential(new ShooterSpinUpCmd());

	AddSequential(new ShooterFireCmdGrp());				// Shoot ball
 }
