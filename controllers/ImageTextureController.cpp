#include "ImageTextureController.h"
#include <algorithm>
#include <QDebug>

ImageTextureController::ImageTextureController(
    ImageController* imageController,
    QObject *parent)
    : QObject{parent},
    m_ImageController(imageController)
{
    Q_ASSERT(imageController);
}

void ImageTextureController::adjustBrightness(int brightness)
{
    cv::Mat src = m_ImageController->originalImage();
    if (src.empty()) return;

    cv::Mat dst;
    src.convertTo(dst, -1, 1.0, brightness);

    m_ImageController->setCurrentImage(dst);
}

void ImageTextureController::adjustContrast(int contrast)
{
    cv::Mat src = m_ImageController->originalImage();
    if (src.empty()) return;

    double alpha = std::clamp(contrast / 100.0 + 1.0, 0.0, 3.0);

    cv::Mat dst;
    src.convertTo(dst, -1, alpha, 0);

    m_ImageController->setCurrentImage(dst);
}

void ImageTextureController::adjustSaturation(int saturation)
{
    cv::Mat src = m_ImageController->originalImage();
    if (src.empty() || src.channels() < 3) return;

    cv::Mat hsv;
    cv::cvtColor(src, hsv, cv::COLOR_BGR2HSV);

    std::vector<cv::Mat> channels;
    cv::split(hsv, channels);

    double scale = std::clamp(saturation / 100.0, 0.0, 3.0);
    channels[1].convertTo(channels[1], -1, scale, 0);

    cv::merge(channels, hsv);

    cv::Mat dst;
    cv::cvtColor(hsv, dst, cv::COLOR_HSV2BGR);

    m_ImageController->setCurrentImage(dst);
}

void ImageTextureController::adjustExposure(int exposure)
{
    cv::Mat src = m_ImageController->originalImage();
    if (src.empty()) return;

    double gamma = std::clamp(exposure / 100.0 + 1.0, 0.1, 3.0);

    cv::Mat dst;
    cv::Mat f;
    src.convertTo(f, CV_32F, 1.0 / 255.0);

    cv::pow(f, 1.0 / gamma, f);
    f *= 255.0;
    f.convertTo(dst, CV_8U);

    m_ImageController->setCurrentImage(dst);
}


void ImageTextureController::adjustGrayScale(int)
{
    cv::Mat src = m_ImageController->originalImage();
    if (src.empty()) return;

    cv::Mat gray, dst;
    cv::cvtColor(src, gray, cv::COLOR_BGR2GRAY);
    cv::cvtColor(gray, dst, cv::COLOR_GRAY2BGR);

    m_ImageController->setCurrentImage(dst);
}

void ImageTextureController::adjustSepia(int sepia)
{
    cv::Mat src = m_ImageController->originalImage();
    if (src.empty()) return;

    double strength = std::clamp(sepia / 100.0, 0.0, 1.0);

    cv::Mat kernel = (cv::Mat_<float>(3,3) <<
                          0.272, 0.534, 0.131,
                      0.349, 0.686, 0.168,
                      0.393, 0.769, 0.189);

    cv::Mat sepiaImg;
    cv::transform(src, sepiaImg, kernel);

    cv::Mat dst;
    cv::addWeighted(src, 1.0 - strength, sepiaImg, strength, 0, dst);

    m_ImageController->setCurrentImage(dst);
}

void ImageTextureController::adjustSharpening(int value)
{
    cv::Mat src = m_ImageController->originalImage();
    if (src.empty()) return;

    double amount = std::clamp(value / 100.0, 0.0, 2.0);

    cv::Mat blurred, dst;
    cv::GaussianBlur(src, blurred, cv::Size(0, 0), 3);

    cv::addWeighted(src, 1 + amount, blurred, -amount, 0, dst);
    m_ImageController->setCurrentImage(dst);
}


void ImageTextureController::adjustInvert(bool enabled)
{
    cv::Mat src = m_ImageController->originalImage();
    if (src.empty()) return;

    if (!enabled)
    {
        m_ImageController->setCurrentImage(src);
        return;
    }

    cv::Mat dst;
    cv::bitwise_not(src, dst);

    m_ImageController->setCurrentImage(dst);
}

