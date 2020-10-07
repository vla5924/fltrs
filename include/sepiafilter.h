#pragma once

#include "precompiled.h"
#include "pointfilter.h"

namespace fltrs
{
    class SepiaFilter : public PointFilter
    {
    protected:
        QColor caclulatePixelColor(QColor color);
    };
} // namespace fltrs
