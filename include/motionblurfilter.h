#pragma once

#include "precompiled.h"
#include "matrixfilter.h"

namespace fltrs
{
    class MotionBlurFilter : public MatrixFilter
    {
    public:
        explicit MotionBlurFilter(int radius = 1);
    };
} // namespace fltrs
