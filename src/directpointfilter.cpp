#include "directpointfilter.h"

QImage fltrs::DirectPointFilter::applyToImage(const QImage& image)
{
    QImage filteredImage(image);
    for (int x = 0; x < image.width(); x++)
        for (int y = 0; y < image.height(); y++)
        {
            QPoint pixelCoord = caclulatePixelCoordinates(QPoint(x, y));
            if (validCoordinate(pixelCoord, image.width(), image.height()))
            {
                pixelCoord.setX(clamp(pixelCoord.x(), 0, image.width() - 1));
                pixelCoord.setY(clamp(pixelCoord.y(), 0, image.height() - 1));
                QColor color = image.pixelColor(pixelCoord);
                filteredImage.setPixelColor(x, y, color);
            }
            else
            {
                filteredImage.setPixelColor(x, y, QColor(0, 0, 0));
            }
            
            
        }
    return filteredImage;
}
