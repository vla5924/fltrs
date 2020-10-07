#pragma once

#include "filter.h"
#include <vector>

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
