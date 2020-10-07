#pragma once

#include "pointfilter.h"

namespace fltrs
{
    class GrayScaleFilter : public PointFilter
    {
    protected:
        QColor caclulatePixelColor(QColor color);
    public:
    };
} // namespace fltrs
