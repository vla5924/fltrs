#pragma once

#include "precompiled.h"
#include "functions.h"
#include "exceptor.h"

namespace fltrs
{
    class Filter
    {
    public:
        virtual QImage applyToImage(const QImage& image) = 0;
    };
}
