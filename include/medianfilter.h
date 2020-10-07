#pragma once

#include "precompiled.h"
#include "dynamicmatrixfilter.h"

namespace fltrs
{
    class MedianFilter : public DynamicMatrixFilter
    {
    protected:
        int calculateProperty(int *values, int valuesCount) const;

    public:
        explicit MedianFilter(int radius = 1);
    };
} // namespace fltrs
