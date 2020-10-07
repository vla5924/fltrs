#pragma once

#include "precompiled.h"
#include "filter.h"

namespace fltrs
{
    class CorrectionFilter : public Filter
    {
    protected:
        virtual QColor caclulatePixelColor(QColor color, const std::vector<float> &metrics) = 0;
        virtual std::vector<float> calculateMetrics(const QImage &image);

    public:
        QImage applyToImage(const QImage &image);
    };
} // namespace fltrs
