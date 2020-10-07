#pragma once

#include "precompiled.h"
#include "exceptor.h"

namespace fltrs
{
    class Filter
    {
    protected:
        template <typename Ty> Ty clamp(Ty value, int min, int max) const;
        bool validCoordinate(QPoint point, int width, int height) const;
        //forEachPixel(const QImage& image, QImage& resultImage, void(*procedure)(QImage& image, int x, int y)) const;
        QColor colorSubtraction(QColor left, QColor right) const;
        float colorIntensity(QColor color) const;
    public:
        virtual QImage applyToImage(const QImage& image) = 0;
    };

    template <typename Ty>
    inline Ty Filter::clamp(Ty value, int min, int max) const
    {
        if (value > max)
            return max;
        if (value < min)
            return min;
        return value;
    }
}
