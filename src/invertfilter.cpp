#include "invertfilter.h"

QColor fltrs::InvertFilter::caclulatePixelColor(QColor color)
{
    QColor newColor(255 - color.red(), 255 - color.green(), 255 - color.blue());
    return newColor;
}
