#pragma once

#include "morphologyfilter.h"
#include "erosionfilter.h"
#include "dilationfilter.h"

namespace fltrs
{
    class ClosingFilter : public MorphologyFilter
    {
    protected:
        DilationFilter dilation;
        ErosionFilter erosion;

    public:
        explicit ClosingFilter(int radius = 1);
        ClosingFilter(const std::vector<bool> &mask);
        QImage applyToImage(const QImage &image);
    };
} // namespace fltrs
