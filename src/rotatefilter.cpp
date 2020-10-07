#include "rotatefilter.h"

inline double fltrs::RotateFilter::getRadians(int angle) const
{
    return 3.141592 * angle / 180.;
}

QPoint fltrs::RotateFilter::caclulatePixelCoordinates(QPoint pixel)
{
    int x = (pixel.x() - xCenter) * cos(getRadians(angle)) - (pixel.y() - yCenter) * sin(getRadians(angle)) + xCenter;
    int y = (pixel.x() - xCenter) * sin(getRadians(angle)) + (pixel.y() - yCenter) * cos(getRadians(angle)) + yCenter;
    return QPoint(x, y);
}

fltrs::RotateFilter::RotateFilter(int xCenter_, int yCenter_, int angle_)
{
    xCenter = xCenter_;
    yCenter = yCenter_;
    angle = angle_;
}
