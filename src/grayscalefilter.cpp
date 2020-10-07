#include "grayscalefilter.h"

QColor fltrs::GrayScaleFilter::caclulatePixelColor(QColor color)
{
    int intensity = 0.36 * color.red() + 0.53 * color.green() + 0.11 * color.blue();
    intensity = clamp(intensity, 0, 255);
    return QColor(intensity, intensity, intensity);
}
