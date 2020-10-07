#pragma once

#include "basematrixfilter.h"
#include <vector>

namespace fltrs
{
    class DynamicMatrixFilter : public BaseMatrixFilter
    {
    protected:
        explicit DynamicMatrixFilter(int matrixRadius_ = 1);
        virtual QColor calculatePixelColor(const QImage &image, int x, int y) const;
        virtual QColor calculatePropertyColor(const QColor *colors, int colorsCount) const;
        virtual int calculateProperty(int *values, int valuesCount) const;
    };
} // namespace fltrs
