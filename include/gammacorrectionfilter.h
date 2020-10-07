#pragma once

#include "precompiled.h"
#include "correctionfilter.h"

namespace fltrs
{
    class GammaCorrectionFilter : public CorrectionFilter
    {
    protected:
        float gamma;
        float coefficient;
        enum metric
        {
        };
        virtual QColor caclulatePixelColor(QColor color, const std::vector<float> &metrics);
        virtual std::vector<float> calculateMetrics(const QImage &image);

    public:
        explicit GammaCorrectionFilter(float gamma_ = 1.0f, float coefficient_ = 1.0f);
    };
} // namespace fltrs
