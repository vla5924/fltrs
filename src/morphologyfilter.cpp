#include "morphologyfilter.h"

fltrs::MorphologyFilter::MorphologyFilter(int matrixRadius_) : DynamicMatrixFilter(matrixRadius_)
{
    int matrixSize = getMatrixSize();
    maskMatrix.resize(matrixRealSize, false);
    for (int i = 0; i < matrixSize; i++)
        for (int j = 0; j < matrixSize; j++)
            if ((i == j) || (j == matrixSize - i - 1))
                maskMatrix[i * matrixSize + j] = true;
    maskPower = matrixRadius * 4 + 1;
}

fltrs::MorphologyFilter::MorphologyFilter(const std::vector<bool>& maskMatrix_)
{
    float eps = std::numeric_limits<float>::epsilon();
    float matrixRadius_ = (sqrt(maskMatrix_.size()) - 1) / 2.0f;
    float ceilMatrixRadius_ = (float)(int)((sqrt(maskMatrix_.size()) - 1) / 2.0f);
    if (matrixRadius_ - ceilMatrixRadius_ >= eps)
        throw InvalidMaskMatrixSize();
    matrixRadius = static_cast<int>(matrixRadius_);
    maskMatrix = maskMatrix_;
    maskPower = 0;
    for (bool mark : maskMatrix)
        maskPower += static_cast<int>(mark);
}

QColor fltrs::MorphologyFilter::calculatePixelColor(const QImage& image, int x, int y) const
{
    QColor* colors = new QColor[maskPower];
    int index = 0, k = 0;
    for (int i = -matrixRadius; i <= matrixRadius; i++)
        for (int j = -matrixRadius; j <= matrixRadius; j++)
        {
            int nearX = clamp(x + j, 0, image.width() - 1);
            int nearY = clamp(y + i, 0, image.height() - 1);
            QColor color = image.pixelColor(nearX, nearY);
            if (maskMatrix[index])
                colors[k++] = color;
            index++;
        }
    QColor color = calculatePropertyColor(colors, maskPower);
    delete[] colors;
    return color;
}
