#pragma once

#include "complexfilter.h"
#include "medianfilter.h"
#include "sobelyfilter.h"
#include "maximumfilter.h"

namespace fltrs
{
    class GlowingEdgesFilter : public ComplexFilter
    {
    public:
        QImage applyToImage(const QImage &image);
    };
} // namespace fltrs
