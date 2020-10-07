#pragma once

#include "matrixfilter.h"
#include <cmath>

namespace fltrs
{
    class GaussianBlurFilter : public MatrixFilter
    {
    public:
        explicit GaussianBlurFilter(int radius = 3, int sigma = 2);
        EXCEPTOR(InvalidSigmaError, "Sigma parameter must have a positive value.");
    };
} // namespace fltrs
