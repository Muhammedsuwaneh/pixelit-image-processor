#ifndef IMAGECROPCONTROLLER_H
#define IMAGECROPCONTROLLER_H

#include <QObject>
#include <opencv2/opencv.hpp>
#include "ImageController.h"

class ImageCropController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int x READ x WRITE setX NOTIFY cropChanged)
    Q_PROPERTY(int y READ y WRITE setY NOTIFY cropChanged)
    Q_PROPERTY(int width READ width WRITE setWidth NOTIFY cropChanged)
    Q_PROPERTY(int height READ height WRITE setHeight NOTIFY cropChanged)

public:
    explicit ImageCropController(ImageController* imageController, QObject *parent = nullptr);

    Q_INVOKABLE void cropImage();

    int x() const;
    void setX(int value);

    int y() const;
    void setY(int value);

    int width() const;
    void setWidth(int value);

    int height() const;
    void setHeight(int value);

signals:
    void cropChanged();

private:
    ImageController* m_ImageController = nullptr;

    int m_x = 0;
    int m_y = 0;
    int m_width = 0;
    int m_height = 0;
};

#endif // IMAGECROPCONTROLLER_H
