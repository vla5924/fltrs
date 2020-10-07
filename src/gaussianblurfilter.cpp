#include "gaussianblurfilter.h"

fltrs::GaussianBlurFilter::GaussianBlurFilter(int radius, int sigma) : MatrixFilter(radius)
{
    if (sigma <= 0)
        throw InvalidSigmaError();
    int matrixSize = getMatrixSize();
    float normCoef = 0;
    for(int i = -matrixRadius; i <= matrixRadius; i++)
        for (int j = -matrixRadius; j <= matrixRadius; j++)
        {
            int index = (i + matrixRadius) * matrixSize + (j + radius);
            matrix[index] = exp(-(i * i + j * j) / (sigma * sigma));
            normCoef += matrix[index];
        }
    for (int i = 0; i < matrixSize; i++)
        for (int j = 0; j < matrixSize; j++)
            matrix[i * matrixSize + j] /= normCoef;
}
