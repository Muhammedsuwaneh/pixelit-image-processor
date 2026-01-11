#ifndef IMAGESCALECONTROLLER_H
#define IMAGESCALECONTROLLER_H

#include <QObject>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include "ImageController.h"

class ImageController;

class ImageScaleController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double zoomFactor READ zoomFactor WRITE setZoomFactor NOTIFY zoomFactorChanged)
public:
    explicit ImageScaleController(ImageController* imageController, QObject *parent = nullptr);
    Q_INVOKABLE void slide(double value);

    double zoomFactor() const;
    void setZoomFactor(double newZoomFactor);

signals:
    void zoomFactorChanged();

private:
    double m_zoomFactor = 20;
    cv::Mat m_image;
    ImageController* m_ImageController = nullptr;
};

#endif // IMAGESCALECONTROLLER_H
