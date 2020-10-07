#include "sobelyfilter.h"

fltrs::SobelYFilter::SobelYFilter() : MatrixFilter()
{
    matrix[0] = -1;
    matrix[1] = -2;
    matrix[2] = -1;
    matrix[3] = 0;
    matrix[4] = 0;
    matrix[5] = 0;
    matrix[6] = 1;
    matrix[7] = 2;
    matrix[8] = 1;
}
