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

    // brightness
    // contrast
    // saturation
    // exposure
    // grayscale
    // sepia

signals:
private:
    ImageController* m_ImageController;
};

#endif // IMAGETEXTURECONTROLLER_H
