#pragma once

#include "EventEditableResponse.h"

class C2dEffect;
class CEntity;

class NOTSA_EXPORT_VTABLE CEventAttractor : public CEventEditableResponse {
public:
    C2dEffect* m_2dEffect;
    CEntity*   m_entity;
    bool       m_bAvoidLookingAtAttractor;

public:
    static void InjectHooks();

    CEventAttractor(C2dEffect* effect, CEntity* entity, bool bAvoidLookingAtAttractor, /* notsa => */eTaskType taskType = TASK_NONE);
    ~CEventAttractor() override;

    eEventType GetEventType() const override { return EVENT_ATTRACTOR; }
    int32 GetEventPriority() const override { return 0; }
    int32 GetLifeTime() override { return 0; }
    bool AffectsPed(CPed* ped) override;
    CEventEditableResponse* CloneEditable() override;

private:
    CEventAttractor* Constructor(C2dEffect* effect, CEntity* entity, bool bAvoidLookingAtAttractor);
    bool AffectsPed_Reversed(CPed* ped);
    CEventEditableResponse* CloneEditable_Reversed();
    static bool IsEffectActive(CEntity* entity, const C2dEffect* effect);
};
VALIDATE_SIZE(CEventAttractor, 0x20);

class NOTSA_EXPORT_VTABLE CEventScriptedAttractor : public CEventAttractor {
public:
    static void InjectHooks();

    CEventScriptedAttractor(C2dEffect* the2dEffect, CEntity* entity, bool bAvoidLookingAtAttractor);
    ~CEventScriptedAttractor() override = default;

    CEventScriptedAttractor* Constructor(C2dEffect* the2dEffect, CEntity* entity, bool bAvoidLookingAtAttractor);
    eEventType GetEventType() const override { return EVENT_SCRIPTED_ATTRACTOR; }
    CEventScriptedAttractor* CloneEditable() override { return new CEventScriptedAttractor(m_2dEffect, m_entity, false); }
};
