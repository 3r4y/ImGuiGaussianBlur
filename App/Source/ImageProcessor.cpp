#include "Global.h"

cv::Mat ImageProcessor::ApplyGaussianBlur(const cv::Mat& src, double sigma) {
    cv::Mat dst;
    cv::GaussianBlur(src, dst, cv::Size(0, 0), sigma);
    return dst;
}
