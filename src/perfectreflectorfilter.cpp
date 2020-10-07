#include "perfectreflectorfilter.h"

QColor fltrs::PerfectReflectorFilter::caclulatePixelColor(QColor color, const std::vector<float>& metrics)
{
    int red = clamp(color.red() * 255 / metrics[metric::redMax], 0, 255);
    int green = clamp(color.green() * 255 / metrics[metric::greenMax], 0, 255);
    int blue = clamp(color.blue() * 255 / metrics[metric::blueMax], 0, 255);
    return QColor(red, green, blue);
}

std::vector<float> fltrs::PerfectReflectorFilter::calculateMetrics(const QImage& image)
{
    float redMax = 0, greenMax = 0, blueMax = 0;
    for (int x = 0; x < image.width(); x++)
        for (int y = 0; y < image.height(); y++)
        {
            QColor color = image.pixelColor(x, y);
            if (color.red() > redMax)
                redMax = color.red();
            if (color.green() > greenMax)
                greenMax = color.green();
            if (color.blue() > blueMax)
                blueMax = color.blue();
        }
    std::vector<float> metrics = { redMax, greenMax, blueMax };
    return metrics;
}
