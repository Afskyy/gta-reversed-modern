#pragma once

#include "FxPrimBP.h"

class FxEmitterPrt_c;

class NOTSA_EXPORT_VTABLE FxEmitterBP_c : public FxPrimBP_c {
public:
    uint16 m_nLodStart;
    uint16 m_nLodEnd;

    bool   m_bHasInfoFlatData;
    bool   m_bHasInfoHeatHazeData;

public:
    static void InjectHooks();

    FxEmitterBP_c();
    ~FxEmitterBP_c() override = default; // 0x4A18F0

    void RenderHeatHaze(RwCamera* camera, uint32, float);
    bool UpdateParticle(float time, FxEmitterPrt_c* emitter);
    FxPrim_c* CreateInstance() override;
    void Update(float time) override;
    bool LoadTextures(FxName32_t* textureNames, int32 version) override;
    bool Load(FILESTREAM file, int32 version, FxName32_t* textureNames) override;
    void Render(RwCamera* camera, uint32 a2, float dayNightBalance, bool bCanRenderHeatHaze) override;
    bool FreePrtFromPrim(FxSystem_c* system) override;
    [[nodiscard]] bool IsFxInfoPresent(int32 type) const;

private:
    FxPrim_c* CreateInstance_Reversed();
    void Update_Reversed(float time);
    bool LoadTextures_Reversed(FxName32_t* textureNames, int32 version);
    bool Load_Reversed(FILESTREAM file, int32 version, FxName32_t* textureNames);
    void Render_Reversed(RwCamera* camera, uint32 a2, float dayNightBalance, bool bCanRenderHeatHaze);
    bool FreePrtFromPrim_Reversed(FxSystem_c* system);
};
VALIDATE_SIZE(FxEmitterBP_c, 0x48);
