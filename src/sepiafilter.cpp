#include "sepiafilter.h"

QColor fltrs::SepiaFilter::caclulatePixelColor(QColor color)
{
    int intensity = 0.36 * color.red() + 0.53 * color.green() + 0.11 * color.blue();
    const float coef = 30;
    int red   = clamp(intensity + 2.0 * coef, 0, 255);
    int green = clamp(intensity + 0.5 * coef, 0, 255);
    int blue  = clamp(intensity - 1.0 * coef, 0, 255);
    return QColor(red, green, blue);
}
