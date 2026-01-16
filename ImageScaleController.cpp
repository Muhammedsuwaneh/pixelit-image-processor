#include "ImageScaleController.h"
#include <QDebug>

ImageScaleController::ImageScaleController(ImageController* imageController, QObject *parent) : QObject{parent}, m_ImageController(imageController)
{
    Q_ASSERT(m_ImageController);
}

void ImageScaleController::slide(double value)
{
    cv::Mat src = this->m_ImageController->originalImage();
    if (src.empty())
        return;

    double factor = value / 100.0;
    if (factor < 0.01)
        factor = 0.01;

    qDebug() << factor;

    setZoomFactor(factor);

    int newWidth  = static_cast<int>(src.cols * factor);
    int newHeight = static_cast<int>(src.rows * factor);

    if (newWidth <= 0 || newHeight <= 0)
        return;

    cv::Mat zoomed;
    cv::resize(src, zoomed, cv::Size(newWidth, newHeight));

    this->m_ImageController->setCurrentImage(zoomed);
}

void ImageScaleController::imageFit(const QString &fitType)
{
    this->setImageFitType(fitType);
}

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

QString ImageScaleController::imageFitType() const
{
    return m_imageFitType;
}

void ImageScaleController::setImageFitType(const QString &newImageFitType)
{
    if (m_imageFitType == newImageFitType)
        return;
    m_imageFitType = newImageFitType;
    emit imageFitTypeChanged();
}
