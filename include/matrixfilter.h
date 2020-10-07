#pragma once

#include "precompiled.h"
#include "basematrixfilter.h"

namespace fltrs
{
    class MatrixFilter : public BaseMatrixFilter
    {
    protected:
        float* matrix;
        explicit MatrixFilter(int matrixRadius_ = 1);
        ~MatrixFilter();
        QColor calculatePixelColor(const QImage& image, int x, int y) const;
    };
} // namespace fltrs
