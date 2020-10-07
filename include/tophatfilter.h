#pragma once

#include "precompiled.h"
#include "morphologyfilter.h"
#include "openingfilter.h"

namespace fltrs
{
    class TopHatFilter : public MorphologyFilter
    {
    protected:
        OpeningFilter opening;
    public:
        explicit TopHatFilter(int radius = 1);
        TopHatFilter(const std::vector<bool>& mask);
        QImage applyToImage(const QImage & image);
    };
} // namespace fltrs
