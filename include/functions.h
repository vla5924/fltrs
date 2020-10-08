#pragma once

#include "precompiled.h"

namespace fltrs
{
    template <typename Ty>
    inline Ty clamp(Ty value, int min, int max)
    {
        if (value > max)
            return max;
        if (value < min)
            return min;
        return value;
    }

    bool validCoordinate(QPoint point, int width, int height);

    QColor colorSubtraction(QColor left, QColor right);

    float colorIntensity(QColor color);
} // namespace fltrs
