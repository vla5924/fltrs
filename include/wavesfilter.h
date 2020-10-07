#pragma once

#include "precompiled.h"
#include "directpointfilter.h"

namespace fltrs
{
    class WavesFilter : public DirectPointFilter
    {
    protected:
        QPoint caclulatePixelCoordinates(QPoint pixel);
    };
} // namespace fltrs
