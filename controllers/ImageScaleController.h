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
    Q_PROPERTY(QString imageFitType READ imageFitType WRITE setImageFitType NOTIFY imageFitTypeChanged)
public:
    explicit ImageScaleController(ImageController* imageController, QObject *parent = nullptr);
    Q_INVOKABLE void slide(double value);
    Q_INVOKABLE void imageFit(const QString &fitType);

    double zoomFactor() const;
    void setZoomFactor(double newZoomFactor);

    QString imageFitType() const;
    void setImageFitType(const QString &newImageFitType);

signals:
    void zoomFactorChanged();

    void imageFitTypeChanged();

private:
    double m_zoomFactor = 20;
    cv::Mat m_image;
    ImageController* m_ImageController = nullptr;
    QString m_imageFitType;
};

#endif // IMAGESCALECONTROLLER_H
