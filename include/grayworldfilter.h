#pragma once

#include "precompiled.h"
#include "correctionfilter.h"

namespace fltrs
{
    class GrayWorldFilter : public CorrectionFilter
    {
    protected:
        enum metric
        {
            redAvg,
            greenAvg,
            blueAvg,
            avg
        };
        virtual QColor caclulatePixelColor(QColor color, const std::vector<float> &metrics);
        virtual std::vector<float> calculateMetrics(const QImage &image);
    };
} // namespace fltrs
