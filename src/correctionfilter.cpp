#include "correctionfilter.h"

std::vector<float> fltrs::CorrectionFilter::calculateMetrics(const QImage& image)
{
    return std::vector<float>();
}

QImage fltrs::CorrectionFilter::applyToImage(const QImage& image)
{
    QImage filteredImage(image);
    std::vector<float> metrics = calculateMetrics(image);
    for (int x = 0; x < image.width(); x++)
        for (int y = 0; y < image.height(); y++)
        {
            QColor color = image.pixelColor(x, y);
            color = caclulatePixelColor(color, metrics);
            filteredImage.setPixelColor(x, y, color);
        }
    return filteredImage;
}
