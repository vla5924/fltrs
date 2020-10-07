#pragma once

#include "morphologyfilter.h"

namespace fltrs
{
    class ErosionFilter : public MorphologyFilter
    {
    protected:
        int calculateProperty(int *values, int valuesCount) const;

    public:
        explicit ErosionFilter(int radius = 1);
        ErosionFilter(const std::vector<bool> &mask);
    };
} // namespace fltrs
