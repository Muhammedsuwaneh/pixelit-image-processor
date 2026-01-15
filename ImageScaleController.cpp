#include "ImageScaleController.h"
#include <QDebug>

ImageScaleController::ImageScaleController(ImageController* imageController, QObject *parent) : QObject{parent}, m_ImageController(imageController)
{
    Q_ASSERT(m_ImageController);
}

void ImageScaleController::slide(double value)
{
    cv::Mat src = m_ImageController->imageToControl();
    if (src.empty())
        return;

    // Clamp zoom safely
    double factor = value / 100.0;
    if (factor < 0.05)
        factor = 0.05;
    if (factor > 10.0)
        factor = 10.0;

    setZoomFactor(factor);

    int newWidth  = static_cast<int>(src.cols * factor);
    int newHeight = static_cast<int>(src.rows * factor);

    // Absolute safety check
    if (newWidth <= 0 || newHeight <= 0)
        return;

    cv::Mat zoomed;
    cv::resize(
        src,
        zoomed,
        cv::Size(newWidth, newHeight),
        0, 0,
        cv::INTER_LINEAR
        );

    m_ImageController->setImage(zoomed);
}

/*void ImageScaleController::imageFit(QString fitType)
{
    qDebug() << fitType;
}*/


double ImageScaleController::zoomFactor() const
{
    return this->m_zoomFactor;
}

void ImageScaleController::setZoomFactor(double newZoomFactor)
{
    if (this->m_zoomFactor == newZoomFactor)
        return;
    this->m_zoomFactor = newZoomFactor;
    emit zoomFactorChanged();
}
