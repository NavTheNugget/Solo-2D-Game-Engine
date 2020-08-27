#pragma once

// RenderEngine Imports
#include "RenderEngine/RenderEngine.hpp"

namespace Solo
{
class Solo
{
    static const float& mEngineVersion = 0.1;
public:
    static float mGetEngineVersion() { return Solo::mEngineVersion; };
};
};
