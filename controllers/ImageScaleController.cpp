#include "ImageScaleController.h"
#include <QtMath>

ImageScaleController::ImageScaleController(ImageController* imageController,
                                           QObject *parent)
    : QObject(parent),
    m_imageController(imageController)
{
    Q_ASSERT(m_imageController);
}

void ImageScaleController::slide(double value)
{
    value = qBound(0.0, value, 100.0);

    const double minZoom = 0.1;
    const double maxZoom = 3.0;

    double normalized = value / 100.0;
    double newZoom = minZoom + normalized * (maxZoom - minZoom);

    if (qFuzzyCompare(m_zoomFactor, newZoom))
        return;

    m_zoomFactor = newZoom;
    emit zoomFactorChanged();
}

void ImageScaleController::imageFit(const QString &fitType)
{
    if (m_imageFitType == fitType)
        return;

    m_imageFitType = fitType;
    emit imageFitTypeChanged();
}

double ImageScaleController::zoomFactor() const
{
    return m_zoomFactor;
}

QString ImageScaleController::imageFitType() const
{
    return m_imageFitType;
}
