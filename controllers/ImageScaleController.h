#ifndef IMAGESCALECONTROLLER_H
#define IMAGESCALECONTROLLER_H

#include <QObject>

class ImageController;

class ImageScaleController : public QObject
{
    Q_OBJECT

    Q_PROPERTY(double zoomFactor READ zoomFactor NOTIFY zoomFactorChanged)

    Q_PROPERTY(QString imageFitType READ imageFitType NOTIFY imageFitTypeChanged)

public:
    explicit ImageScaleController(ImageController* imageController, QObject *parent = nullptr);

    Q_INVOKABLE void slide(double value);

    Q_INVOKABLE void imageFit(const QString &fitType);

    double zoomFactor() const;
    QString imageFitType() const;

signals:
    void zoomFactorChanged();
    void imageFitTypeChanged();

private:
    ImageController* m_imageController = nullptr;

    double m_zoomFactor = 1.0;          // GPU scale factor
    QString m_imageFitType = "Aspect Fit";
};

#endif // IMAGESCALECONTROLLER_H
