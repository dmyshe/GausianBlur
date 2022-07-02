#include "include/Blur.h"

#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"


cv::Mat src;
cv::Mat dst;
cv::Size matrix;


Blur::Blur() {
    matrix = cv::Size(0, 0);
}

void Blur::setSource(std::string path) {
    src = cv::imread(cv::samples::findFile(path), cv::IMREAD_COLOR);
    if (src.empty())
    {
        return;
    }
    dst = src.clone();
}

void Blur::setBlurAmount(uint32_t j) {
    if (j % 2 == 1) {
        matrix = cv::Size(j, j);
    }
    else {
        ++j;
        matrix = cv::Size(j, j);
    }
}

const std::vector<uint8_t> Blur::dataChanged() {
    array.clear();
    GaussianBlur(src, dst, matrix, 0, 0);

    if (dst.isContinuous()) {
        array.assign((uint8_t*)dst.datastart, (uint8_t*)dst.dataend);
        //array.assign((float*)dst.data, (float*)dst.data + dst.total() * dst.channels());
    }
    else {
        for (int i = 0; i < dst.rows; ++i) {
            array.insert(array.end(), dst.ptr<uint8_t>(i), dst.ptr<uint8_t>(i) + dst.cols * dst.channels());
        }
    }
    return array;

}

int Blur::getChannels(){
    return src.channels();
}
int Blur::getRows(){
    return src.rows;
}
int Blur::getCols(){
    return src.cols;
}

