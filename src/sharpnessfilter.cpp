#include "sharpnessfilter.h"

fltrs::SharpnessFilter::SharpnessFilter() : MatrixFilter()
{
    matrix[0] = 0;
    matrix[1] = -1;
    matrix[2] = 0;
    matrix[3] = -1;
    matrix[4] = 5;
    matrix[5] = -1;
    matrix[6] = 0;
    matrix[7] = -1;
    matrix[8] = 0;
}