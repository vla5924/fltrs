#pragma once

#include "precompiled.h"
#include "matrixfilter.h"

namespace fltrs
{
    class GaussianBlurFilter : public MatrixFilter
    {
    public:
        explicit GaussianBlurFilter(int radius = 3, int sigma = 2);
        EXCEPTOR(InvalidSigmaError, "Sigma parameter must have a positive value.");
    };
} // namespace fltrs
