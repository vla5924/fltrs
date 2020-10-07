#pragma once

#include "filter.h"

namespace fltrs
{
    class DirectPointFilter : public Filter
    {
    protected:
        virtual QPoint caclulatePixelCoordinates(QPoint pixel) = 0;

    public:
        QImage applyToImage(const QImage &image);
    };
} // namespace fltrs
