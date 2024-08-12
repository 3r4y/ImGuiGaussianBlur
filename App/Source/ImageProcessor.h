#pragma once

class ImageProcessor {
public:
    static cv::Mat ApplyGaussianBlur(const cv::Mat& src, double sigma);
};
