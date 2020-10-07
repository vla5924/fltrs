#pragma once

#include "dynamicmatrixfilter.h"
#include <cmath>

namespace fltrs
{
    class MorphologyFilter : public DynamicMatrixFilter
    {
    protected:
        std::vector<bool> maskMatrix;
        int maskPower;
        explicit MorphologyFilter(int matrixRadius_ = 1);
        MorphologyFilter(const std::vector<bool>& maskMatrix_);
        QColor calculatePixelColor(const QImage& image, int x, int y) const;
    public:
        EXCEPTOR(InvalidMaskMatrixSize, "Error...");
    };
} // namespace fltrs
