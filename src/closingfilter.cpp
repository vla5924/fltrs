#include "closingfilter.h"

fltrs::ClosingFilter::ClosingFilter(int radius) : MorphologyFilter(radius)
{
    dilation = DilationFilter(radius);
    erosion = ErosionFilter(radius);
}

fltrs::ClosingFilter::ClosingFilter(const std::vector<bool>& mask) : MorphologyFilter(mask)
{
    dilation = DilationFilter(mask);
    erosion = ErosionFilter(mask);
}

QImage fltrs::ClosingFilter::applyToImage(const QImage& image)
{
    QImage filteredImage = dilation.applyToImage(image);
    filteredImage = erosion.applyToImage(filteredImage);
    return filteredImage;
}