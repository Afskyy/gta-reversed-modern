#pragma once

#include "TaskComplex.h"
#include "Vehicle.h"
#include "Accident.h"

class CTaskComplexMedicTreatInjuredPed : public CTaskComplex {
public:
    CVehicle*  m_pVehicle;
    CPed*      m_pPartnerMedic;
    uint8      m_bIsDriver;
    CAccident* m_pAccident;
    CVector    m_vecAccidentPosition;
    uint8      m_bLeftCarOnce;

public:
    static constexpr auto Type = TASK_COMPLEX_MEDIC_TREAT_INJURED_PED;

    CTaskComplexMedicTreatInjuredPed(CVehicle* vehicle, CPed* ped, bool isDriver);
    ~CTaskComplexMedicTreatInjuredPed() override;

    eTaskType GetTaskType() override { return Type; }
    CTask* Clone() override;
    CTask* CreateFirstSubTask(CPed* ped) override;
    CTask* CreateNextSubTask(CPed* ped) override;
    CTask* ControlSubTask(CPed* ped) override;

    CTask* CreateSubTask(eTaskType taskType);
    CTask* CreateDealWithNextAccidentTask(CPed* ped, CAccident* accident);
    void   FindNearestAccident(CVector& posn);
    void   FindAccidentPosition(CPed* ped, CPed* targetPed);

private:
    friend void InjectHooksMain();
    static void InjectHooks();

    CTaskComplexMedicTreatInjuredPed* Constructor(CVehicle* vehicle, CPed* ped, bool isDriver);

    CTask* Clone_Reversed();
    CTask* CreateFirstSubTask_Reversed(CPed* ped);
    CTask* CreateNextSubTask_Reversed(CPed* ped);
    CTask* ControlSubTask_Reversed(CPed* ped);
};

VALIDATE_SIZE(CTaskComplexMedicTreatInjuredPed, 0x2C);
