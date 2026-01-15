#include "ImageRotationController.h"
#include <QDebug>

ImageRotationController::ImageRotationController(ImageController* imageController, QObject *parent) : QObject{parent}, m_ImageController(imageController)
{
    Q_ASSERT(imageController);
}

void ImageRotationController::rotateImage(signed int angle)
{
    qDebug() << angle;
    cv::Mat src = this->m_ImageController->imageToControl(); // get current image
    // doc: https://docs.opencv.org/3.4/db/dd6/classcv_1_1RotatedRect.html

    if(src.empty()) return;

    cv::Point2f center(src.cols / 2.0f, src.rows / 2.0f); // calculate center point of image
    cv::Mat rot = cv::getRotationMatrix2D(center, angle, 1.0); // create 2x3 affine transformation matrix

    /*[
     * cos@ -sin@ tx
     * sin@ cos@ ty
     * ]*/

    cv::Rect2f boundingBox = cv::RotatedRect(cv::Point2f(), src.size(), angle).boundingRect2f(); // calculate bounding box to contain image while rotating

    // adjust translations
    rot.at<double>(0, 2) += boundingBox.width / 2.0 - src.cols / 2.0;
    rot.at<double>(1, 2) += boundingBox.height / 2.0 - src.rows / 2.0;

    cv::Mat dst;
    cv::warpAffine(src, dst, rot, boundingBox.size());

    this->m_ImageController->setImage(dst); // update image
}

signed int ImageRotationController::rotationAngle() const
{
    return m_rotationAngle;
}

void ImageRotationController::setRotationAngle(signed int newRotationAngle)
{
    if (m_rotationAngle == newRotationAngle)
        return;
    m_rotationAngle = newRotationAngle;
    emit rotationAngleChanged();
}
