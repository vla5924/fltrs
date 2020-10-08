cmake_minimum_required(VERSION 3.0.0)
project(fltrs)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(Qt5_DIR cmake)

find_package(Qt5 COMPONENTS Core Gui REQUIRED)

include_directories(include)

add_library(fltrs STATIC
    src/basematrixfilter.cpp
    src/blackhatfilter.cpp
    src/blurfilter.cpp
    src/brightnessfilter.cpp
    src/closingfilter.cpp
    src/complexfilter.cpp
    src/correctionfilter.cpp
    src/dilationfilter.cpp
    src/directpointfilter.cpp
    src/dynamicmatrixfilter.cpp
    src/erosionfilter.cpp
    src/filter.cpp
    src/functions.cpp
    src/gaussianblurfilter.cpp
    src/glowingedgesfilter.cpp
    src/grayscalefilter.cpp
    src/grayworldfilter.cpp
    src/invertfilter.cpp
    src/linearcorrectionfilter.cpp
    src/matrixfilter.cpp
    src/maximumfilter.cpp
    src/medianfilter.cpp
    src/morphologyfilter.cpp
    src/motionblurfilter.cpp
    src/openingfilter.cpp
    src/perfectreflectorfilter.cpp
    src/pointfilter.cpp
    src/referencecolorfilter.cpp
    src/rotatefilter.cpp
    src/sepiafilter.cpp
    src/sharpnessfilter.cpp
    src/shiftfilter.cpp
    src/sobelyfilter.cpp
    src/tophatfilter.cpp
    src/wavesfilter.cpp
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

target_link_libraries(fltrs Qt5::Core Qt5::Gui)

add_subdirectory(sample)
