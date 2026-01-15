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
    Q_PROPERTY(cv::Mat imageToControl READ imageToControl NOTIFY imageToControlChanged)
public:
    explicit ImageController(QObject *parent = nullptr);
    Q_INVOKABLE void loadImage();

    QImage image() const;
    cv::Mat imageToControl() const;
    void setImage(cv::Mat image);

signals:
    void imageChanged();
    void imageToControlChanged();

private:
    QImage m_image;
    cv::Mat m_imageToControl;
    QImage matToImage(const cv::Mat &mat);
};

#endif // IMAGECONTROLLER_H
