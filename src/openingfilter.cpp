#include "openingfilter.h"

fltrs::OpeningFilter::OpeningFilter(int radius) : MorphologyFilter(radius)
{
    dilation = DilationFilter(radius);
    erosion = ErosionFilter(radius);
}

fltrs::OpeningFilter::OpeningFilter(const std::vector<bool>& mask) : MorphologyFilter(mask)
{
    dilation = DilationFilter(mask);
    erosion = ErosionFilter(mask);
}

QImage fltrs::OpeningFilter::applyToImage(const QImage& image)
{
    QImage filteredImage = erosion.applyToImage(image);;
    filteredImage = dilation.applyToImage(filteredImage);
    return filteredImage;
}