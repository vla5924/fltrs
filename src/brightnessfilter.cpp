#include "brightnessfilter.h"

QColor fltrs::BrightnessFilter::caclulatePixelColor(QColor color)
{
    int red   = clamp(color.red()   + delta, 0, 255);
    int green = clamp(color.green() + delta, 0, 255);
    int blue  = clamp(color.blue()  + delta, 0, 255);
    return QColor(red, green, blue);
}

fltrs::BrightnessFilter::BrightnessFilter(int delta_)
{
    delta = delta_;
}
