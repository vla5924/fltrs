#include "medianfilter.h"

int fltrs::MedianFilter::calculateProperty(int* values, int valuesCount) const
{
    std::sort(values, values + valuesCount);
    return values[valuesCount / 2U];
}


fltrs::MedianFilter::MedianFilter(int radius) : DynamicMatrixFilter(radius)
{
}
