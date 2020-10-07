#pragma once

/* Qt libraries */
#include <QtCore/QCoreApplication>
#include <QImage>

/* standard libraries */
#include <string>
#include <cstring>
#include <ciso646>
#include <iostream>
#include <vector>

/* point filters */
#include "invertfilter.h"
#include "grayscalefilter.h"
#include "sepiafilter.h"
#include "brightnessfilter.h"

/* direct point filters */
#include "shiftfilter.h"
#include "wavesfilter.h"
#include "rotatefilter.h"

/* matrix filters */
#include "blurfilter.h"
#include "gaussianblurfilter.h"
#include "sobelyfilter.h"
#include "sharpnessfilter.h"
#include "motionblurfilter.h"

/* dynamic matrix filters */
#include "medianfilter.h"
#include "maximumfilter.h"

/* morphology filters */
#include "dilationfilter.h"
#include "erosionfilter.h"
#include "openingfilter.h"
#include "closingfilter.h"
#include "tophatfilter.h"
#include "blackhatfilter.h"

/* complex filters */
#include "glowingedgesfilter.h"

/* correction filters */
#include "linearcorrectionfilter.h"
#include "grayworldfilter.h"
#include "perfectreflectorfilter.h"
#include "referencecolorfilter.h"
#include "gammacorrectionfilter.h"
