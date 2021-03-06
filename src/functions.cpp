#include "functions.h"

bool fltrs::validCoordinate(QPoint point, int width, int height)
{
    bool xValid = (point.x() >= 0) && (point.x() <= width - 1);
    bool yValid = (point.y() >= 0) && (point.y() <= height - 1);
    return xValid && yValid;
}

QColor fltrs::colorSubtraction(QColor left, QColor right)
{
    int red   = clamp(left.red()   - right.red(),   0, 255);
    int green = clamp(left.green() - right.green(), 0, 255);
    int blue  = clamp(left.blue()  - right.blue(),  0, 255);
    return QColor(red, green, blue);
}

float fltrs::colorIntensity(QColor color)
{
    return 0.36 * color.red() + 0.53 * color.green() + 0.11 * color.blue();
}
