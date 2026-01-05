#ifndef IMAGECONTROLLER_H
#define IMAGECONTROLLER_H

#include <QObject>
#include <QUrl>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <QImage>
#include "ImageProvider.h"

class ImageController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QUrl imageSource READ imageSource NOTIFY imageSourceChanged)
public:
    explicit ImageController(QObject *parent = nullptr);
    Q_INVOKABLE void loadImage();
    Q_INVOKABLE void saveImage(const QUrl &imageSource);
    void setProvider(ImageProvider *provider);

    QUrl imageSource() const;

signals:
    void imageSourceChanged();

private:
    cv::Mat Image;
    QImage m_image;

    QImage matToImage(const cv::Mat &mat);
    ImageProvider *m_provider;
    QUrl m_imageSource;
};

#endif // IMAGECONTROLLER_H
