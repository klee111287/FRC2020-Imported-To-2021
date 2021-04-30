#pragma once

#include <frc/PIDController.h>
#include <rev/CANSparkMax.h>
#include <frc/SpeedControllerGroup.h>
#include <frc/controller/PIDController.h>


using namespace rev;

class PIDShooter 
{
    frc2::PIDController *pid;
    frc::SpeedControllerGroup *motors;
    rev::CANSparkMax *master; 
    int rpm;

    public:
    PIDShooter(CANSparkMax &m1, CANSparkMax &m2, int RPM = 2000)
    {
        m1.SetInverted(true);
        master = &m1;
        rpm = RPM;
        motors = new frc::SpeedControllerGroup(m1, m2);
        pid = new frc2::PIDController(0, 0, 0);
    }

    void run()
    {
        // motors->Get()
        motors->Set(pid->Calculate(master->GetEncoder().GetVelocity(), rpm));
    }
};