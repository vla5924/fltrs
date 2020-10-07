#pragma once

#include "filter.h"
#include <vector>

namespace fltrs
{
    class BaseMatrixFilter : public Filter
    {
    protected:
        int matrixRadius;
        int matrixRealSize;
        explicit BaseMatrixFilter(int matrixRadius_ = 1);
        int getMatrixSize() const { return 2 * matrixRadius + 1; }
        virtual QColor calculatePixelColor(const QImage &image, int x, int y) const = 0;

    public:
        QImage applyToImage(const QImage &image);
        EXCEPTOR(InvalidRadiusError, "Radius must be a positive integer.");
    };

} // namespace fltrs
