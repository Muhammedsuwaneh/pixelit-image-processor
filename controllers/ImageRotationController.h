#ifndef IMAGEROTATIONCONTROLLER_H
#define IMAGEROTATIONCONTROLLER_H

#include <QObject>
#include "ImageController.h"

class ImageController;

class ImageRotationController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double rotationAngle READ rotationAngle WRITE setRotationAngle NOTIFY rotationAngleChanged)
public:
    explicit ImageRotationController(ImageController* imageController, QObject *parent = nullptr);
    Q_INVOKABLE void rotateImage(double angle);

    double rotationAngle() const;
    void setRotationAngle(double newRotationAngle);

signals:

    void rotationAngleChanged();

private:
    ImageController* m_ImageController;
    double m_rotationAngle;
};

#endif // IMAGEROTATIONCONTROLLER_H
