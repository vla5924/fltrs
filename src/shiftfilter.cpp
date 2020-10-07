#include "shiftfilter.h"

QPoint fltrs::ShiftFilter::caclulatePixelCoordinates(QPoint pixel)
{
    int x = pixel.x() + dx;
    int y = pixel.y() + dy;
    return QPoint(x, y);
}

fltrs::ShiftFilter::ShiftFilter(int dx_, int dy_)
{
    dx = dx_;
    dy = dy_;
}
