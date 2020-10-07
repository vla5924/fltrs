#include "wavesfilter.h"

QPoint fltrs::WavesFilter::caclulatePixelCoordinates(QPoint pixel)
{
    int x = pixel.x() + 20 * sin(2 * 3.141592 * pixel.x() / 30.);
    int y = pixel.y();
    return QPoint(x, y);
}
