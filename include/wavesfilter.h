#pragma once

#include "directpointfilter.h"
#include <cmath>

namespace fltrs
{
    class WavesFilter : public DirectPointFilter
    {
    protected:
        QPoint caclulatePixelCoordinates(QPoint pixel);
    };
} // namespace fltrs
