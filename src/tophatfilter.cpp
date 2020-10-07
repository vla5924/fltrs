#include "tophatfilter.h"

fltrs::TopHatFilter::TopHatFilter(int radius) : MorphologyFilter(radius)
{
    opening = OpeningFilter(radius);
}

fltrs::TopHatFilter::TopHatFilter(const std::vector<bool>& mask) : MorphologyFilter(mask)
{
    opening = OpeningFilter(mask);
}

QImage fltrs::TopHatFilter::applyToImage(const QImage& image)
{
    QImage filteredImage = opening.applyToImage(image);
    for (int x = 0; x < image.width(); x++)
        for (int y = 0; y < image.height(); y++)
        {
            QColor color = colorSubtraction(image.pixelColor(x, y), filteredImage.pixelColor(x, y));
            filteredImage.setPixelColor(x, y, color);
        }
    return filteredImage;
}