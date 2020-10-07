#include "maximumfilter.h"

int fltrs::MaximumFilter::calculateProperty(int* values, int valuesCount) const
{
    int max = values[0];
    for (int i = 1; i < valuesCount; i++)
        if (values[i] > max)
            max = values[i];
    return max;
}

fltrs::MaximumFilter::MaximumFilter(int radius) : DynamicMatrixFilter(radius)
{
}
