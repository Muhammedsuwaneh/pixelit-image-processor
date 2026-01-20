#ifndef IMAGERESIZECONTROLLER_H
#define IMAGERESIZECONTROLLER_H

#include <QObject>
#include "ImageController.h"
#include <opencv2/opencv.hpp>

class ImageResizeController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int targetWidth READ targetWidth WRITE setTargetWidth NOTIFY targetWidthChanged)
    Q_PROPERTY(int targetHeight READ targetHeight WRITE setTargetHeight NOTIFY targetHeightChanged)
public:
    explicit ImageResizeController(ImageController* imageController, QObject *parent = nullptr);

    int targetWidth() const;
    void setTargetWidth(int newTargetWidth);

    int targetHeight() const;
    void setTargetHeight(int newTargetHeight);

    Q_INVOKABLE void resizeImage();

signals:


    void targetWidthChanged();

    void targetHeightChanged();

private:

    int m_targetWidth;
    int m_targetHeight;
    ImageController* m_ImageController;
};

#endif // IMAGERESIZECONTROLLER_H
