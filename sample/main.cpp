#include "fltrs.inc"

int main(int argc, char *argv[])
{
    std::string fileName;
    for (int i = 0; i < argc; i++)
        if (!strcmp(argv[i], "-p") and (i + 1 < argc))
            fileName = argv[i + 1];

    QImage image, filteredImage;
    image.load(fileName.c_str());

    std::cout << "Copying\n";
    image.save("test_copy.png");

    std::cout << "Applying filter: Invert\n";
    fltrs::InvertFilter invFilter;
    filteredImage = invFilter.applyToImage(image);
    filteredImage.save("test_inv.png");

    std::cout << "Applying filter: Rotate(20, 40, 30)\n";
    fltrs::RotateFilter rotateFilter(20, 40, 30);
    filteredImage = rotateFilter.applyToImage(image);
    filteredImage.save("test_rotate.png");

    std::cout << "Applying filter: GrayScale\n";
    fltrs::GrayScaleFilter grayFilter;
    filteredImage = grayFilter.applyToImage(image);
    filteredImage.save("test_gray.png");

    std::cout << "Applying filter: Sepia\n";
    fltrs::SepiaFilter sepiaFilter;
    filteredImage = sepiaFilter.applyToImage(image);
    filteredImage.save("test_sepia.png");

    std::cout << "Applying filter: Brightness(50)\n";
    fltrs::BrightnessFilter brightnessFilter(50);
    filteredImage = brightnessFilter.applyToImage(image);
    filteredImage.save("test_brightness.png");

    std::cout << "Applying filter: Blur(3)\n";
    fltrs::BlurFilter blurFilter(3);
    filteredImage = blurFilter.applyToImage(image);
    filteredImage.save("test_blur.png");

    std::cout << "Applying filter: GaussianBlur\n";
    fltrs::GaussianBlurFilter gBlurFilter;
    filteredImage = gBlurFilter.applyToImage(image);
    filteredImage.save("test_gblur.png");

    std::cout << "Applying filter: SobelY\n";
    fltrs::SobelYFilter sobelFilter;
    filteredImage = sobelFilter.applyToImage(image);
    filteredImage.save("test_sobel.png");

    std::cout << "Applying filter: Sharpness\n";
    fltrs::SharpnessFilter sharpnessFilter;
    filteredImage = sharpnessFilter.applyToImage(image);
    filteredImage.save("test_sharpness.png");

    std::cout << "Applying filter: Median(1)\n";
    fltrs::MedianFilter median1Filter(1);
    filteredImage = median1Filter.applyToImage(image);
    filteredImage.save("test_median1.png");

    std::cout << "Applying filter: Median(10)\n";
    fltrs::MedianFilter median2Filter(10);
    filteredImage = median2Filter.applyToImage(image);
    filteredImage.save("test_median10.png");

    std::cout << "Applying filter: Shift(30, 10)\n";
    fltrs::ShiftFilter shiftFilter(30, 10);
    filteredImage = shiftFilter.applyToImage(image);
    filteredImage.save("test_shift.png");

    std::cout << "Applying filter: Waves\n";
    fltrs::WavesFilter wavesFilter;
    filteredImage = wavesFilter.applyToImage(image);
    filteredImage.save("test_waves.png");
    
    std::cout << "Applying filter: Motion blur(4)\n";
    fltrs::MotionBlurFilter mBlurFilter(4);
    filteredImage = mBlurFilter.applyToImage(image);
    filteredImage.save("test_mblur.png");

    std::cout << "Applying filter: Maximum(2)\n";
    fltrs::MaximumFilter maximumFilter(2);
    filteredImage = maximumFilter.applyToImage(image);
    filteredImage.save("test_max.png");
    
    std::cout << "Applying filter: Glowing Edges\n";
    fltrs::GlowingEdgesFilter glowingEdgesFilter;
    filteredImage = glowingEdgesFilter.applyToImage(image);
    filteredImage.save("test_gedges.png");

    std::vector<bool> morphMask = {
        1, 0, 0, 0, 1,
        0, 1, 0, 1, 0,
        0, 0, 1, 0, 0,
        0, 1, 0, 1, 0,
        1, 0, 0, 0, 1
    };

    std::vector<bool> morph2Mask = {
        0, 1, 1, 1, 0,
        1, 1, 1, 1, 1,
        1, 1, 1, 1, 1,
        1, 1, 1, 1, 1,
        0, 1, 1, 1, 0
    };

    std::cout << "Applying filter: Dilation(2)\n";
    fltrs::DilationFilter dilationFilter(morphMask);
    filteredImage = dilationFilter.applyToImage(image);
    filteredImage.save("test_dilation.png");

    std::cout << "Applying filter: Erosion(2)\n";
    fltrs::ErosionFilter erosionFilter(morphMask);
    filteredImage = erosionFilter.applyToImage(image);
    filteredImage.save("test_erosion.png");

    std::cout << "Applying filter: Opening(2)\n";
    fltrs::OpeningFilter openingFilter(morphMask);
    filteredImage = openingFilter.applyToImage(image);
    filteredImage.save("test_opening.png");

    std::cout << "Applying filter: Closing(2)\n";
    fltrs::ClosingFilter closingFilter(morphMask);
    filteredImage = closingFilter.applyToImage(image);
    filteredImage.save("test_closing.png");

    std::cout << "Applying filter: TopHat(2)\n";
    fltrs::TopHatFilter topHatFilter(morphMask);
    filteredImage = topHatFilter.applyToImage(image);
    filteredImage.save("test_tophat.png");

    std::cout << "Applying filter: BlackHat(2)\n";
    fltrs::BlackHatFilter blackHatFilter(morph2Mask);
    filteredImage = blackHatFilter.applyToImage(image);
    filteredImage.save("test_blackhat.png");

    std::cout << "Applying filter: Linear correction\n";
    fltrs::LinearCorrectionFilter linearFilter;
    filteredImage = linearFilter.applyToImage(image);
    filteredImage.save("test_linear.png");

    std::cout << "Applying filter: Gray World\n";
    fltrs::GrayWorldFilter grayWorldFilter;
    filteredImage = grayWorldFilter.applyToImage(image);
    filteredImage.save("test_grayworld.png");

    return 0;
}
