#pragma once

#include "precompiled.h"
#include "filter.h"

namespace fltrs
{
    class ComplexFilter : public Filter
    {
    public:
        QImage applyToImage(const QImage &image) = 0;
    };
} // namespace fltrs
