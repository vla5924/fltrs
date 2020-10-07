#include "linearcorrectionfilter.h"

QColor fltrs::LinearCorrectionFilter::caclulatePixelColor(QColor color, const std::vector<float>& metrics)
{
    int red = (color.red() - metrics[metric::redMin]) * 255 / (metrics[metric::redMax] - metrics[metric::redMin]);
    int green = (color.green() - metrics[metric::greenMin]) * 255 / (metrics[metric::greenMax] - metrics[metric::greenMin]);
    int blue = (color.blue() - metrics[metric::blueMin]) * 255 / (metrics[metric::blueMax] - metrics[metric::blueMin]);
    return QColor(red, green, blue);
}

std::vector<float> fltrs::LinearCorrectionFilter::calculateMetrics(const QImage& image)
{
    float redMin = 255, greenMin = 255, blueMin = 255;
    float redMax = 0, greenMax = 0, blueMax = 0;
    for (int x = 0; x < image.width(); x++)
        for (int y = 0; y < image.height(); y++)
        {
            QColor color = image.pixelColor(x, y);
            if (color.red() < redMin)
                redMin = color.red();
            if (color.green() < greenMin)
                greenMin = color.green();
            if (color.blue() < blueMin)
                blueMin = color.blue();
            if (color.red() > redMax)
                redMax = color.red();
            if (color.green() > greenMax)
                greenMax = color.green();
            if (color.blue() > blueMax)
                blueMax = color.blue();
        }
    std::vector<float> metrics = { redMin, greenMin, blueMin, redMax, greenMax, blueMax };
    return metrics;
}
