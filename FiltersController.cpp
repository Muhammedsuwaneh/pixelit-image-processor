#include "FiltersController.h"
#include <opencv2/opencv.hpp>

FiltersController::FiltersController(ImageController* imageController, QObject *parent)
    : QObject{parent},
    m_ImageController(imageController)
{
    Q_ASSERT(imageController);
}

void FiltersController::applyFilter(const QString& filter)
{
    if (!m_ImageController)
        return;

    if (filter == "Gray Scale")
        applyGrayFilter();
    else if (filter == "Sepia")
        applySepia();
    else if (filter == "Gaussian Blur Filter")
        applyGaussianBlur();
    else if (filter == "Sharpen")
        applySharpen();
    else if (filter == "Edge Detection Filter")
        applyEdgeDetection();
}

void FiltersController::applyGrayFilter()
{
    cv::Mat src = m_ImageController->originalImage();
    if (src.empty())
        return;

    cv::Mat gray, dst;
    cv::cvtColor(src, gray, cv::COLOR_BGR2GRAY);
    cv::cvtColor(gray, dst, cv::COLOR_GRAY2BGR); // keep 3 channels

    m_ImageController->setCurrentImage(dst);
}

void FiltersController::applySepia()
{
    cv::Mat src = m_ImageController->originalImage();
    if (src.empty())
        return;

    cv::Mat sepia;
    cv::Mat kernel = (cv::Mat_<float>(3,3) <<
                          0.272, 0.534, 0.131,
                      0.349, 0.686, 0.168,
                      0.393, 0.769, 0.189
                      );

    cv::transform(src, sepia, kernel);
    sepia.convertTo(sepia, CV_8UC3); // clamp values

    m_ImageController->setCurrentImage(sepia);
}

void FiltersController::applyGaussianBlur()
{
    cv::Mat src = m_ImageController->originalImage();
    if (src.empty())
        return;

    cv::Mat blurred;
    cv::GaussianBlur(src, blurred, cv::Size(9, 9), 0);

    m_ImageController->setCurrentImage(blurred);
}

void FiltersController::applySharpen()
{
    cv::Mat src = m_ImageController->originalImage();
    if (src.empty())
        return;

    cv::Mat sharpened;
    cv::Mat kernel = (cv::Mat_<float>(3,3) <<
                          0, -1,  0,
                      -1,  5, -1,
                      0, -1,  0
                      );

    cv::filter2D(src, sharpened, -1, kernel);

    m_ImageController->setCurrentImage(sharpened);
}


void FiltersController::applyEdgeDetection()
{
    cv::Mat src = m_ImageController->originalImage();
    if (src.empty())
        return;

    cv::Mat gray, edges, dst;
    cv::cvtColor(src, gray, cv::COLOR_BGR2GRAY);
    cv::Canny(gray, edges, 100, 200);
    cv::cvtColor(edges, dst, cv::COLOR_GRAY2BGR);

    m_ImageController->setCurrentImage(dst);
}
