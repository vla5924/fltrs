#pragma once

#include "correctionfilter.h"

namespace fltrs
{
    class PerfectReflectorFilter : public CorrectionFilter
    {
    protected:
        enum metric { redMax, greenMax, blueMax };
        virtual QColor caclulatePixelColor(QColor color, const std::vector<float>& metrics);
        virtual std::vector<float> calculateMetrics(const QImage& image);
    };
} // namespace fltrs
