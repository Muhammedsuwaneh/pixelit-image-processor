#ifndef IMAGEPROVIDER_H
#define IMAGEPROVIDER_H

#include "controllers/ImageController.h"
#include <QQuickImageProvider>
#include <QImage>

class ImageController;

class ImageProvider : public QQuickImageProvider
{

public:
    explicit ImageProvider(ImageController* imageController);
    QImage requestImage(const QString&, QSize*size, const QSize&) override;

private:
    ImageController* m_ImageController;
};

#endif // IMAGEPROVIDER_H
