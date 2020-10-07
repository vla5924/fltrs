#pragma once

#include "precompiled.h"
#include "matrixfilter.h"

namespace fltrs
{
    class BlurFilter : public MatrixFilter
    {
    public:
        explicit BlurFilter(int radius = 1);
    };
} // namespace fltrs
