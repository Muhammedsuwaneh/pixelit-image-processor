#include "ImageScaleController.h"
#include <QDebug>

ImageScaleController::ImageScaleController(QObject *parent)
    : QObject{parent}
{}

void ImageScaleController::slide(double value)
{
    this->setZoomFactor(value);
    qDebug() << value;

    // apply image resizing
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
