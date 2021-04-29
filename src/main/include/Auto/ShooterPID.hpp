#pragma once

#include <frc/PIDController.h>
#include <rev/CANSparkMax.h>
#include <frc/SpeedControllerGroup.h>


using namespace rev;

class PIDShooter 
{
    frc::PIDController *pid;
    frc::SpeedControllerGroup *motors;

    public:
    PIDShooter(CANSparkMax &m1, CANSparkMax &m2)
    {
        motors = new frc::SpeedControllerGroup(m1, m2);
        rev::CANEncoder
        pid = new frc::PIDController(0, 0, 0, m1.GetEncoder(), motors);
    }
};