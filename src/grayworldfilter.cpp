#include "grayworldfilter.h"

QColor fltrs::GrayWorldFilter::caclulatePixelColor(QColor color, const std::vector<float>& metrics)
{
    int red = color.red() * metrics[metric::avg] / metrics[metric::redAvg];
    int green = color.green() * metrics[metric::avg] / metrics[metric::greenAvg];
    int blue = color.blue() * metrics[metric::avg] / metrics[metric::blueAvg];
    return QColor(clamp(red, 0, 255), clamp(green, 0, 255), clamp(blue, 0, 255));
}

std::vector<float> fltrs::GrayWorldFilter::calculateMetrics(const QImage& image)
{
    unsigned long long pixelsCount = image.width() * image.height();
    unsigned long long red = 0, green = 0, blue = 0;
    for (int x = 0; x < image.width(); x++)
        for (int y = 0; y < image.height(); y++)
        {
            QColor color = image.pixelColor(x, y);
            red += static_cast<unsigned long long>(color.red());
            green += static_cast<unsigned long long>(color.green());
            blue += static_cast<unsigned long long>(color.blue());
        }
    float redAvg = static_cast<float>(red / pixelsCount);
    float greenAvg = static_cast<float>(green / pixelsCount);
    float blueAvg = static_cast<float>(blue / pixelsCount);
    float avg = (redAvg + greenAvg + blueAvg) / 3.0f;
    std::vector<float> metrics = { redAvg, greenAvg, blueAvg, avg };
    return metrics;
}
