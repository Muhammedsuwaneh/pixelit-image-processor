#ifndef IMAGESCALECONTROLLER_H
#define IMAGESCALECONTROLLER_H

#include <QObject>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>

class ImageScaleController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double zoomFactor READ zoomFactor WRITE setZoomFactor NOTIFY zoomFactorChanged)
public:
    explicit ImageScaleController(QObject *parent = nullptr);
    Q_INVOKABLE void slide(double value);

    double zoomFactor() const;
    void setZoomFactor(double newZoomFactor);

signals:
    void zoomFactorChanged();

private:
    double m_zoomFactor = 20;
};

#endif // IMAGESCALECONTROLLER_H
