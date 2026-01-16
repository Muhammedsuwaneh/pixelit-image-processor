#include "ImageTextureController.h"

ImageTextureController::ImageTextureController(ImageController* imageController, QObject *parent): QObject{parent}, m_ImageController(imageController)
{
    Q_ASSERT(imageController);
}

void ImageTextureController::adjustBrightness(int brightness)
{
    cv::Mat src = this->m_ImageController->imageToControl();
    if(src.empty()) return;

    double val = brightness / 100.0;

    cv::Mat dst;
    src.convertTo(dst, -1, 1, val);
    this->m_ImageController->setImage(dst);
}

void ImageTextureController::adjustContrast(int contrast)
{
    double val = contrast / 100.0;

    cv::Mat src = this->m_ImageController->imageToControl();
    cv::Mat dst;
    src.convertTo(dst, -1, val, 0);
    this->m_ImageController->setImage(dst);
}

void ImageTextureController::adjustSaturation(int saturation)
{
    cv::Mat src = this->m_ImageController->imageToControl();
    if(src.empty()) return;

    cv::Mat hsv;
    cv::cvtColor(src, hsv, cv::COLOR_BGR2HSV);

    std::vector<cv::Mat> channels;
    cv::split(hsv, channels);

    double val = saturation / 100.0;
    channels[1].convertTo(channels[1], -1, val, 0);
    cv::merge(channels, hsv);

    cv::Mat dst;
    cv::cvtColor(hsv, dst, cv::COLOR_HSV2BGR);

    this->m_ImageController->setImage(dst);
}

void ImageTextureController::adjustExposure(int exposure)
{
    cv::Mat src = this->m_ImageController->imageToControl();
    if(src.empty()) return;

    double val = exposure / 100.0;
    cv::Mat dst;
    src.convertTo(dst, -1, val, 0);
    this->m_ImageController->setImage(dst);
}

void ImageTextureController::adjustGrayScale(int grayScale)
{
    cv::Mat src = this->m_ImageController->imageToControl();
    if(src.empty()) return;

    double val = grayScale / 100.0;
    cv::Mat dst;
    cv::cvtColor(src, dst, cv::COLOR_BGR2GRAY);
    this->m_ImageController->setImage(dst);
}

void ImageTextureController::adjustSepia(int sepia)
{
    cv::Mat src = this->m_ImageController->imageToControl();
    if(src.empty()) return;

    double val = sepia / 100.0;
    cv::Mat dst;

    cv::Mat kernel = (cv::Mat_<float>(3,3) <<
                          0.272, 0.534, 0.131,
                      0.349, 0.686, 0.168,
                      0.393, 0.769, 0.189);

    cv::transform(src, dst, kernel);
    this->m_ImageController->setImage(dst);
}

void ImageTextureController::adjustSharpening(int val)
{
    cv::Mat src = this->m_ImageController->imageToControl();
    if(src.empty()) return;

    auto amount = val / 100.0 * 1.5;

    amount = std::clamp(amount, 0.0, 1.5);

    cv::Mat blurred, dst;
    cv::GaussianBlur(src, blurred, cv::Size(0, 0), 5);

    cv::addWeighted(src, 1 + amount, blurred, -amount, 0, dst);
    this->m_ImageController->setImage(dst);
}
