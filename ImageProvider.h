#ifndef IMAGEPROVIDER_H
#define IMAGEPROVIDER_H

#include <QQuickImageProvider>
#include <QImage>

class ImageProvider : public QQuickImageProvider
{

public:
    explicit ImageProvider();
    QImage requestImage(const QString&, QSize*size, const QSize&) override;

    void setImage(const QImage &img);

private:
    QImage m_image;
};

#endif // IMAGEPROVIDER_H
