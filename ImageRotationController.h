#ifndef IMAGEROTATIONCONTROLLER_H
#define IMAGEROTATIONCONTROLLER_H

#include <QObject>
#include "ImageController.h"

class ImageController;

class ImageRotationController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(signed int rotationAngle READ rotationAngle WRITE setRotationAngle NOTIFY rotationAngleChanged)
public:
    explicit ImageRotationController(ImageController* imageController, QObject *parent = nullptr);
    Q_INVOKABLE void rotateImage(signed int angle);

    signed int rotationAngle() const;
    void setRotationAngle(signed int newRotationAngle);

signals:

    void rotationAngleChanged();

private:
    ImageController* m_ImageController;
    signed int m_rotationAngle;
};

#endif // IMAGEROTATIONCONTROLLER_H
