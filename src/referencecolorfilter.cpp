#include "referencecolorfilter.h"

QColor fltrs::ReferenceColorFilter::caclulatePixelColor(QColor color, const std::vector<float>& metrics)
{
    int red = clamp(color.red() * metrics[metric::redCoef], 0, 255);
    int green = clamp(color.green() * metrics[metric::greenCoef], 0, 255);
    int blue = clamp(color.blue() * metrics[metric::blueCoef], 0, 255);
    return QColor(red, green, blue);
}

std::vector<float> fltrs::ReferenceColorFilter::calculateMetrics(QColor sourceColor, QColor controlColor)
{
    float redCoef = controlColor.red() / sourceColor.red();
    float greenCoef = controlColor.green() / sourceColor.green();
    float blueCoef = controlColor.blue() / sourceColor.blue();
    std::vector<float> metrics = { redCoef, greenCoef, blueCoef };
    return metrics;
}

QImage fltrs::ReferenceColorFilter::applyToImage(const QImage& image, QPoint controlPixel, QColor controlColor)
{
    QImage filteredImage(image);
    std::vector<float> metrics = calculateMetrics(image.pixelColor(controlPixel), controlColor);
    for (int x = 0; x < image.width(); x++)
        for (int y = 0; y < image.height(); y++)
        {
            QColor color = image.pixelColor(x, y);
            color = caclulatePixelColor(color, metrics);
            filteredImage.setPixelColor(x, y, color);
        }
    return filteredImage;
}
