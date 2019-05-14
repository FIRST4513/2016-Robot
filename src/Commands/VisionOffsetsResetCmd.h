// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef VISIONOFFSETSRESETCMD_H
#define VISIONOFFSETSRESETCMD_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class VisionOffsetsResetCmd: public Command {
public:
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR
	VisionOffsetsResetCmd(int mode);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=VARIABLES

    int m_mode;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=VARIABLES

    float xOffset, yOffset;							// temporary holding places
    float targetHt = 94;										// default target Ht

    std::shared_ptr<NetworkTable> netTable;						// Pointer for accessing the NetworkTables

};

#endif
