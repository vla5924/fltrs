#include "motionblurfilter.h"

fltrs::MotionBlurFilter::MotionBlurFilter(int radius) : MatrixFilter(radius)
{
    int matrixSize = getMatrixSize();
    for (int i = 0; i < matrixSize; i++)
        for (int j = 0; j < matrixSize; j++)
            if (i == j)
                matrix[i * matrixSize + j] = 1.0f / matrixSize;
            else
                matrix[i * matrixSize + j] = 0.0f;
}
