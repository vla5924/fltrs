#pragma once

#include "morphologyfilter.h"

namespace fltrs
{
    class DilationFilter : public MorphologyFilter
    {
        friend class TOpeningFilter;
    protected:
        int calculateProperty(int* values, int valuesCount) const;
    public:
        explicit DilationFilter(int radius = 1);
        DilationFilter(const std::vector<bool>& mask);
    };
} // namespace fltrs
