#pragma once

#include "precompiled.h"
#include "correctionfilter.h"

namespace fltrs
{
    class LinearCorrectionFilter : public CorrectionFilter
    {
    protected:
        enum metric { redMin, greenMin, blueMin, redMax, greenMax, blueMax };
        virtual QColor caclulatePixelColor(QColor color, const std::vector<float> & metrics);
        virtual std::vector<float> calculateMetrics(const QImage & image);
    };
} // namespace fltrs
