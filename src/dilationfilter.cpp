#include "dilationfilter.h"

int fltrs::DilationFilter::calculateProperty(int* values, int valuesCount) const
{
    int max = values[0];
    for (int i = 1; i < valuesCount; i++)
        if (values[i] > max)
            max = values[i];
    return max;
}

fltrs::DilationFilter::DilationFilter(int radius) : MorphologyFilter(radius)
{
}

fltrs::DilationFilter::DilationFilter(const std::vector<bool>& mask) : MorphologyFilter(mask)
{
}
