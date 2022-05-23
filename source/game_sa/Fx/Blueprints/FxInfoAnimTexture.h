#pragma once

#include "FxInfo.h"
#include "FxInterpInfo32.h"

class FxInfoAnimTexture_c : public FxInfo_c {
protected:
    FxInterpInfo32_c m_InterpInfo;

public:
    FxInfoAnimTexture_c();
    ~FxInfoAnimTexture_c() override = default; // 0x4A78F0

    void Load(FILESTREAM file, int32 version) override;
    void GetValue(float currentTime, float mult, float totalTime, float length, bool bConstTimeSet, void* info) override;
};
