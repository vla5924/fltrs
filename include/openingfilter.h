#pragma once

#include "precompiled.h"
#include "morphologyfilter.h"
#include "dilationfilter.h"
#include "erosionfilter.h"

namespace fltrs
{
    class OpeningFilter : public MorphologyFilter
    {
    protected:
        ErosionFilter erosion;
        DilationFilter dilation;
    public:
        explicit OpeningFilter(int radius = 1);
        OpeningFilter(const std::vector<bool>& mask);
        QImage applyToImage(const QImage& image);
    };
} // namespace fltrs
