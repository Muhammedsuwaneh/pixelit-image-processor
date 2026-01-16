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
    Q_PROPERTY(cv::Mat defaultImageToControl READ defaultImageToControl NOTIFY defaultImageToControlChanged)
public:
    explicit ImageController(QObject *parent = nullptr);
    Q_INVOKABLE void loadImage();
    Q_INVOKABLE void restoreToDefault();

    QImage image() const;
    cv::Mat imageToControl() const;
    void setImage(cv::Mat image);

    cv::Mat defaultImageToControl() const;

signals:
    void imageChanged();
    void imageToControlChanged();

    void defaultImageToControlChanged();

private:
    QImage m_image;
    cv::Mat m_imageToControl;
    QImage matToImage(const cv::Mat &mat);
    cv::Mat m_defaultImageToControl;
};

#endif // IMAGECONTROLLER_H
