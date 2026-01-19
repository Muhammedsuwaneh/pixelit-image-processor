#ifndef IMAGECONTROLLER_H
#define IMAGECONTROLLER_H

#include <QObject>
#include <QImage>
#include <opencv2/opencv.hpp>

class ImageController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QImage image READ image NOTIFY imageChanged)

public:
    explicit ImageController(QObject *parent = nullptr);

    Q_INVOKABLE void loadImage();
    Q_INVOKABLE void restoreToDefault();

    // Display image (QML)
    QImage image() const;

    // OpenCV access
    cv::Mat originalImage() const;
    cv::Mat currentImage() const;

    // Used by filters / rotation
    void setCurrentImage(const cv::Mat& image);

signals:
    void imageChanged();

private:
    QImage matToImage(const cv::Mat &mat);

private:
    QImage  m_qimage;          // shown in QML
    cv::Mat m_originalImage;   // NEVER changes
    cv::Mat m_currentImage;    // derived image
};

#endif // IMAGECONTROLLER_H
