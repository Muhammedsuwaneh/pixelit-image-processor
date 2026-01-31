#include "ImageRotationController.h"
#include <QDebug>

ImageRotationController::ImageRotationController(ImageController* imageController, QObject *parent) : QObject{parent}, m_ImageController(imageController)
{
    Q_ASSERT(imageController);
}

void ImageRotationController::rotateImage(double angle)
{
    cv::Mat src = m_ImageController->editBaseImage();

    if (src.empty())
        return;

    cv::Point2f center(src.cols / 2.0f, src.rows / 2.0f);

    cv::Mat rot = cv::getRotationMatrix2D(center, angle, 1.0);

    cv::Rect2f bbox =
        cv::RotatedRect(cv::Point2f(), src.size(), angle).boundingRect2f();

    rot.at<double>(0,2) += bbox.width  / 2.0 - src.cols / 2.0;
    rot.at<double>(1,2) += bbox.height / 2.0 - src.rows / 2.0;

    cv::Mat dst;
    cv::warpAffine(src, dst, rot, bbox.size(), cv::INTER_LINEAR);

    m_ImageController->setCurrentImage(dst);
}

double ImageRotationController::rotationAngle() const
{
    return m_rotationAngle;
}

void ImageRotationController::setRotationAngle(double newRotationAngle)
{
    if (m_rotationAngle == newRotationAngle)
        return;
    m_rotationAngle = newRotationAngle;
    emit rotationAngleChanged();
}
