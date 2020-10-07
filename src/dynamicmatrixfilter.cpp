#include "dynamicmatrixfilter.h"

fltrs::DynamicMatrixFilter::DynamicMatrixFilter(int matrixRadius_) : BaseMatrixFilter(matrixRadius_)
{
}

QColor fltrs::DynamicMatrixFilter::calculatePixelColor(const QImage& image, int x, int y) const
{
    QColor* colors = new QColor[matrixRealSize];
    int k = 0;
    for (int i = -matrixRadius; i <= matrixRadius; i++)
        for (int j = -matrixRadius; j <= matrixRadius; j++)
        {
            int nearX = clamp(x + j, 0, image.width() - 1);
            int nearY = clamp(y + i, 0, image.height() - 1);
            QColor color = image.pixelColor(nearX, nearY);
            colors[k++] = color;
        }
    QColor color = calculatePropertyColor(colors, matrixRealSize);
    delete[] colors;
    return color;
}

QColor fltrs::DynamicMatrixFilter::calculatePropertyColor(const QColor* colors, int colorsCount) const
{
    int* red = new int[colorsCount];
    int* green = new int[colorsCount];
    int* blue = new int[colorsCount];
    for (int i = 0; i < colorsCount; i++)
    {
        red[i] = colors[i].red();
        green[i] = colors[i].green();
        blue[i] = colors[i].blue();
    }
    int redColor = calculateProperty(red, colorsCount);
    int greenColor = calculateProperty(green, colorsCount);
    int blueColor = calculateProperty(blue, colorsCount);
    redColor = clamp(redColor, 0, 255);
    greenColor = clamp(greenColor, 0, 255);
    blueColor = clamp(blueColor, 0, 255);
    delete[] red;
    delete[] green;
    delete[] blue;
    return QColor(redColor, greenColor, blueColor);
}

int fltrs::DynamicMatrixFilter::calculateProperty(int* values, int valuesCount) const
{
    return 0;
}
