#pragma once

#include "pointfilter.h"

namespace fltrs
{
    class InvertFilter : public PointFilter
    {
    protected:
        QColor caclulatePixelColor(QColor color);

    };
} // namespace fltrs
