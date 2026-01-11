#include "ImageScaleController.h"
#include <QDebug>

ImageScaleController::ImageScaleController(ImageController* imageController, QObject *parent) : QObject{parent}, m_ImageController(imageController)
{
    Q_ASSERT(m_ImageController);
    // get image
}

void ImageScaleController::slide(double value)
{
    this->setZoomFactor(value);
    qDebug() << value;

    // apply image resizing

    // set image
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
