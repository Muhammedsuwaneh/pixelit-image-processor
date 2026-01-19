#include "ImageProvider.h"

ImageProvider::ImageProvider(ImageController* imageController)
    : QQuickImageProvider(QQuickImageProvider::Image), m_ImageController(imageController)  {}

QImage ImageProvider::requestImage(const QString &, QSize *size, const QSize &requestedSize)
{
    QImage image = this->m_ImageController->image();

    if(image.isNull())
        return QImage();

    if (size)
        *size = image.size();

    if (requestedSize.isValid())
        return image.scaled(requestedSize, Qt::KeepAspectRatio);

    return image;
}

