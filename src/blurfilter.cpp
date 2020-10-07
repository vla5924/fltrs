#include "blurfilter.h"

fltrs::BlurFilter::BlurFilter(int radius) : MatrixFilter(radius)
{
    int matrixSize = getMatrixSize();
    for (int i = 0; i < matrixSize; i++)
        for (int j = 0; j < matrixSize; j++)
            matrix[i * matrixSize + j] = 1.0f / (matrixSize * matrixSize);
}
