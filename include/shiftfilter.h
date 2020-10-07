#pragma once

#include "directpointfilter.h"

namespace fltrs
{
    class ShiftFilter : public DirectPointFilter
    {
    protected:
        QPoint caclulatePixelCoordinates(QPoint pixel);
    public:
        int dx, dy;
        explicit ShiftFilter(int dx_ = 0, int dy_ = 0);
    };
} // namespace fltrs
