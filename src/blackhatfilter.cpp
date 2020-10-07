#include "blackhatfilter.h"

fltrs::BlackHatFilter::BlackHatFilter(int radius) : MorphologyFilter(radius)
{
    closing = ClosingFilter(radius);
}

fltrs::BlackHatFilter::BlackHatFilter(const std::vector<bool>& mask) : MorphologyFilter(mask)
{
    closing = ClosingFilter(mask);
}

QImage fltrs::BlackHatFilter::applyToImage(const QImage& image)
{
    QImage filteredImage = closing.applyToImage(image);
    for (int x = 0; x < image.width(); x++)
        for (int y = 0; y < image.height(); y++)
        {
            QColor color = colorSubtraction(filteredImage.pixelColor(x, y), image.pixelColor(x, y));
            filteredImage.setPixelColor(x, y, color);
        }
    return filteredImage;
}