#include "basematrixfilter.h"

fltrs::BaseMatrixFilter::BaseMatrixFilter(int matrixRadius_)
{
    if (matrixRadius_ < 1)
        throw InvalidRadiusError();
    matrixRadius = matrixRadius_;
    matrixRealSize = getMatrixSize() * getMatrixSize();
}

QImage fltrs::BaseMatrixFilter::applyToImage(const QImage& image)
{
    QImage filteredImage(image);
    for (int x = 0; x < image.width(); x++)
        for (int y = 0; y < image.height(); y++)
        {
            QColor color = calculatePixelColor(image, x, y);
            filteredImage.setPixelColor(x, y, color);
        }
    return filteredImage;
}
