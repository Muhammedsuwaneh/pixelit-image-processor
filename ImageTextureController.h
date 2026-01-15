#ifndef IMAGETEXTURECONTROLLER_H
#define IMAGETEXTURECONTROLLER_H

#include <QObject>
#include "ImageController.h"

class ImageController;

class ImageTextureController : public QObject
{
    Q_OBJECT
public:
    explicit ImageTextureController(ImageController* imageController, QObject *parent = nullptr);

    Q_INVOKABLE void adjustBrightness(int brightness);
    Q_INVOKABLE void adjustContrast(int contrast);
    Q_INVOKABLE void adjustSaturation(int saturation);
    Q_INVOKABLE void adjustExposure(int exposure);
    Q_INVOKABLE void adjustGrayScale(int grayScale);
    Q_INVOKABLE void adjustSepia(int sepia);

signals:
private:
    ImageController* m_ImageController;
};

#endif // IMAGETEXTURECONTROLLER_H
