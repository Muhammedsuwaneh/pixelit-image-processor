#ifndef IMAGECONTROLLER_H
#define IMAGECONTROLLER_H

#include <QObject>
#include <QImage>
#include <opencv2/opencv.hpp>
#include <vector>

class ImageController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QImage image READ image NOTIFY imageChanged)
    Q_PROPERTY(cv::Mat originalImage READ originalImage NOTIFY originalImageChanged)

public:
    explicit ImageController(QObject *parent = nullptr);

    Q_INVOKABLE void loadImage();
    Q_INVOKABLE void restoreToDefault();

    Q_INVOKABLE void undo();
    Q_INVOKABLE void redo();

    Q_INVOKABLE void commit();
    Q_INVOKABLE void saveImage();

    QImage image() const;

    cv::Mat originalImage() const;
    cv::Mat editBaseImage() const;
    cv::Mat currentImage() const;

    void setCurrentImage(const cv::Mat& image);

signals:
    void imageChanged();
    void originalImageChanged();

private:
    QImage matToImage(const cv::Mat &mat);

private:
    QImage  m_qimage;
    cv::Mat m_originalImage;
    cv::Mat m_currentImage;
    cv::Mat m_editBaseImage;

    std::vector<cv::Mat> m_undoStack;
    std::vector<cv::Mat> m_redoStack;
};

#endif // IMAGECONTROLLER_H
