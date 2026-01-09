#ifndef IMAGECONTROLLER_H
#define IMAGECONTROLLER_H

#include <QObject>
#include <QUrl>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <QImage>

class ImageController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QImage image READ image NOTIFY imageChanged)
public:
    explicit ImageController(QObject *parent = nullptr);
    Q_INVOKABLE void loadImage();

    QImage image() const;

signals:
    void imageChanged();

private:
    QImage m_image;
    QImage matToImage(const cv::Mat &mat);
};

#endif // IMAGECONTROLLER_H
