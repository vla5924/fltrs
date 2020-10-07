#pragma once

#include "dynamicmatrixfilter.h"

namespace fltrs
{
    class MaximumFilter : public DynamicMatrixFilter
    {
    protected:
        int calculateProperty(int* values, int valuesCount) const;
    public:
        explicit MaximumFilter(int radius = 1);
    };
} // namespace fltrs
