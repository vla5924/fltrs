#pragma once

#include "directpointfilter.h"
#include <cmath>

namespace fltrs
{
    class RotateFilter : public DirectPointFilter
    {
    protected:
        inline double getRadians(int angle) const;
        QPoint caclulatePixelCoordinates(QPoint pixel);
    public:
        int xCenter, yCenter;
        int angle;
        explicit RotateFilter(int xCenter_ = 0, int yCenter_ = 0, int angle_ = 0);
    };
} // namespace fltrs
