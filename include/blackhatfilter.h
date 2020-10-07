#pragma once

#include "precompiled.h"
#include "morphologyfilter.h"
#include "closingfilter.h"

namespace fltrs
{
    class BlackHatFilter : public MorphologyFilter
    {
    protected:
        ClosingFilter closing;

    public:
        explicit BlackHatFilter(int radius = 1);
        BlackHatFilter(const std::vector<bool> &mask);
        QImage applyToImage(const QImage &image);
    };
} // namespace fltrs
