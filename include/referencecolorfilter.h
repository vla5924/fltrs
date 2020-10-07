#pragma once

#include "precompiled.h"
#include "correctionfilter.h"

namespace fltrs
{
    class ReferenceColorFilter : public CorrectionFilter
    {
    protected:
        enum metric { redCoef, greenCoef, blueCoef };
        virtual QColor caclulatePixelColor(QColor color, const std::vector<float>& metrics);
        virtual std::vector<float> calculateMetrics(QColor sourceColor, QColor controlColor);
    public:
        QImage applyToImage(const QImage& image, QPoint sourcePixel, QColor controlColor);
    };
} // namespace fltrs
