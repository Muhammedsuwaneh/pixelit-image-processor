#include "FiltersController.h"

FiltersController::FiltersController(ImageController* imageController, QObject *parent)
    : QObject{parent}, m_ImageController(imageController)
{
    Q_ASSERT(imageController);
}

void FiltersController::applyFilter(QString filter)
{
    if(filter == "Gray Scale") ApplyGrayFilter();
    else if("Sepia") ApplySepia();
    else if("Gaussian Blur Filter") ApplyGaussianBlur();
    else if("Sharpen") ApplySharpen();
    else if("Edge Detection Filter") ApplyEdgeDetection();
}

void FiltersController::ApplyGrayFilter()
{
    cv::Mat src = this->m_ImageController->imageToControl();
    if(src.empty()) return;

    cv::Mat dst;
    cv::cvtColor(src, dst, cv::COLOR_BGR2GRAY);
    cv::cvtColor(dst, dst, cv::COLOR_GRAY2BGR); // keep 3 channels

    this->m_ImageController->setImage(dst);
}

void FiltersController::ApplySepia()
{
    cv::Mat src = this->m_ImageController->imageToControl();
    if(src.empty()) return;

    cv::Mat sepia;
    cv::Mat kernel = (cv::Mat_<float>(3,3) <<
                          0.272, 0.534, 0.131,
                      0.349, 0.686, 0.168,
                      0.393, 0.769, 0.189
                      );

    cv::transform(src, sepia, kernel);
    sepia.convertTo(sepia, CV_8UC3); // clamp values

    this->m_ImageController->setImage(sepia);
}

void FiltersController::ApplyGaussianBlur()
{
    cv::Mat src = this->m_ImageController->imageToControl();
    if(src.empty()) return;

    cv::Mat blurred;
    cv::GaussianBlur(src, blurred, cv::Size(9, 9), 0);

    this->m_ImageController->setImage(blurred);
}

void FiltersController::ApplySharpen()
{
    cv::Mat src = this->m_ImageController->imageToControl();
    if(src.empty()) return;

    cv::Mat sharpened;
    cv::Mat kernel = (cv::Mat_<float>(3,3) <<
                          0, -1,  0,
                      -1,  5, -1,
                      0, -1,  0
                      );

    cv::filter2D(src, sharpened, -1, kernel);

    this->m_ImageController->setImage(sharpened);
}

void FiltersController::ApplyEdgeDetection()
{
    cv::Mat src = this->m_ImageController->imageToControl();
    if(src.empty()) return;

    cv::Mat gray, edges, result;
    cv::cvtColor(src, gray, cv::COLOR_BGR2GRAY);
    cv::Canny(gray, edges, 100, 200);
    cv::cvtColor(edges, result, cv::COLOR_GRAY2BGR);

    this->m_ImageController->setImage(result);
}
