#include "glowingedgesfilter.h"

QImage fltrs::GlowingEdgesFilter::applyToImage(const QImage& image)
{
    QImage filteredImage;
    MedianFilter medianFilter;
    SobelYFilter sobelFilter;
    MaximumFilter maximumFilter;
    filteredImage = medianFilter.applyToImage(image);
    filteredImage = sobelFilter.applyToImage(filteredImage);
    filteredImage = maximumFilter.applyToImage(filteredImage);
    return filteredImage;
}
