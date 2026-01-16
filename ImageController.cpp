#include "ImageController.h"
#include <QFileDialog>

ImageController::ImageController(QObject *parent) : QObject{parent}, m_image(QImage()) {}

QImage ImageController::matToImage(const cv::Mat &mat)
{
    switch(mat.type())
    {
        case CV_8UC1:
        return QImage(mat.data, mat.cols, mat.rows, mat.step, QImage::Format_Grayscale8).copy();
        case CV_8UC3:
            return QImage(mat.data, mat.cols, mat.rows, mat.step, QImage::Format_BGR888).copy();
        case CV_8UC4:
            return QImage(mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGBA8888).copy();

        return QImage();
    }

    return QImage();
}

void ImageController::loadImage()
{
    const QString filePath = QFileDialog::getOpenFileName(nullptr, "Select Image", QString(), "Images (*.png *.jpg *.jpeg *.bmp");

    if(!filePath.isEmpty())
    {
        this->m_imageToControl = cv::imread(filePath.toStdString());

        if(this->m_imageToControl.empty()) return;

        this->m_image = matToImage(this->m_imageToControl);

        this->m_defaultImageToControl = this->m_imageToControl;

        emit imageChanged();
        emit imageToControlChanged();
        emit defaultImageToControlChanged();
    }
}

void ImageController::restoreToDefault()
{
    this->setImage(this->m_defaultImageToControl);
}

QImage ImageController::image() const
{
    return this->m_image;
}

cv::Mat ImageController::imageToControl() const
{
    return this->m_imageToControl;
}

void ImageController::setImage(cv::Mat image)
{
    this->m_imageToControl = image;

    this->m_image = matToImage(this->m_imageToControl);

    emit imageToControlChanged();
    emit imageChanged();
}

cv::Mat ImageController::defaultImageToControl() const
{
    return m_defaultImageToControl;
}
