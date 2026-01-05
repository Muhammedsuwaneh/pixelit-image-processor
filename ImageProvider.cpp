#include "ImageProvider.h"

ImageProvider::ImageProvider() : QQuickImageProvider(QQuickImageProvider::Image) {}

QImage ImageProvider::requestImage(const QString &, QSize *size, const QSize &requestedSize)
{
    if(this->m_image.isNull())
        return QImage();

    if (size)
        *size = this->m_image.size();

    if (requestedSize.isValid())
        return this->m_image.scaled(requestedSize, Qt::KeepAspectRatio);

    return this->m_image;
}

void ImageProvider::setImage(const QImage &img)
{
    this->m_image = img;
}

