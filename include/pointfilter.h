#pragma once

#include "filter.h"

namespace fltrs
{
    class PointFilter : public Filter
    {
    protected:
        virtual QColor caclulatePixelColor(QColor color) = 0;
    public:
        QImage applyToImage(const QImage& image);
    };
} // namespace fltrs
