#include "ImageController.h"
#include <QFileDialog>

ImageController::ImageController(QObject *parent)
    : QObject(parent)
{
}

QImage ImageController::matToImage(const cv::Mat &mat)
{
    if (mat.empty())
        return QImage();

    switch (mat.type())
    {
    case CV_8UC1:
        return QImage(mat.data, mat.cols, mat.rows, mat.step,
                      QImage::Format_Grayscale8).copy();

    case CV_8UC3:
        return QImage(mat.data, mat.cols, mat.rows, mat.step,
                      QImage::Format_BGR888).copy();

    case CV_8UC4:
        return QImage(mat.data, mat.cols, mat.rows, mat.step,
                      QImage::Format_RGBA8888).copy();

    default:
        return QImage();
    }
}

void ImageController::loadImage()
{
    const QString filePath =
        QFileDialog::getOpenFileName(nullptr,
                                     "Select Image",
                                     QString(),
                                     "Images (*.png *.jpg *.jpeg *.bmp)");

    if (filePath.isEmpty())
        return;

    cv::Mat img = cv::imread(filePath.toStdString(), cv::IMREAD_UNCHANGED);
    if (img.empty())
        return;

    // Store original ONCE
    this->m_originalImage = img.clone();
    this->m_currentImage  = img.clone();

    this->m_qimage = matToImage(m_currentImage);
    emit imageChanged();
}

void ImageController::restoreToDefault()
{
    if (m_originalImage.empty())
        return;

    this->m_currentImage = this->m_originalImage.clone();
    this->m_qimage = matToImage(this->m_currentImage);

    emit imageChanged();
}

QImage ImageController::image() const
{
    return this->m_qimage;
}

cv::Mat ImageController::originalImage() const
{
    return this->m_originalImage;
}

cv::Mat ImageController::currentImage() const
{
    return this->m_currentImage;
}

void ImageController::setCurrentImage(const cv::Mat& image)
{
    if (image.empty())
        return;

    this->m_currentImage = image.clone();
    this->m_qimage = matToImage(m_currentImage);

    emit imageChanged();
}
