#pragma once

#include "precompiled.h"
#include "pointfilter.h"

namespace fltrs
{
    class BrightnessFilter : public PointFilter
    {
    protected:
        QColor caclulatePixelColor(QColor color);
    public:
        int delta;
        explicit BrightnessFilter(int delta = 0);
    };
} // namespace fltrs
