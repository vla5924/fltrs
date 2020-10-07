#include "erosionfilter.h"

int fltrs::ErosionFilter::calculateProperty(int* values, int valuesCount) const
{
    int min = values[0];
    for (int i = 1; i < valuesCount; i++)
        if (values[i] < min)
            min = values[i];
    return min;
}

fltrs::ErosionFilter::ErosionFilter(int radius) : MorphologyFilter(radius)
{
}

fltrs::ErosionFilter::ErosionFilter(const std::vector<bool>& mask) : MorphologyFilter(mask)
{
}