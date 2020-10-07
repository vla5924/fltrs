#include "pointfilter.h"

QImage fltrs::PointFilter::applyToImage(const QImage& image)
{
    QImage filteredImage(image);
    for (int x = 0; x < image.width(); x++)
        for (int y = 0; y < image.height(); y++)
        {
            QColor color = image.pixelColor(x, y);
            color = caclulatePixelColor(color);
            filteredImage.setPixelColor(x, y, color);
        }
    return filteredImage;
}
