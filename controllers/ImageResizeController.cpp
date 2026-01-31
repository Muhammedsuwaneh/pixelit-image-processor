#include "ImageResizeController.h"
#include <QDebug>

ImageResizeController::ImageResizeController(ImageController* imageController, QObject *parent)
    : QObject{parent}, m_ImageController(imageController)
{
    Q_ASSERT(imageController);
}

int ImageResizeController::targetWidth() const
{
    return this->m_targetWidth;
}

int ImageResizeController::targetHeight() const
{
    return m_targetHeight;
}

void ImageResizeController::setTargetWidth(int newTargetWidth)
{
    if (m_targetWidth == newTargetWidth)
        return;
    m_targetWidth = newTargetWidth;
    emit targetWidthChanged();
}

void ImageResizeController::setTargetHeight(int newTargetHeight)
{
    if (m_targetHeight == newTargetHeight)
        return;
    m_targetHeight = newTargetHeight;
    emit targetHeightChanged();
}

void ImageResizeController::resizeImage()
{
    try
    {
        cv::Mat src = m_ImageController->editBaseImage();
        if (src.empty())
            return;

        qDebug() << "Before resizing: " << src.rows << " - " << src.cols;

        if (this->m_targetWidth <= 0 || this->m_targetHeight <= 0)
            return;

        cv::Mat resized;
        cv::resize(src, resized, cv::Size(m_targetWidth, m_targetHeight));

        this->m_ImageController->setCurrentImage(resized);

        qDebug() << "Before resizing: " << m_ImageController->currentImage().rows << " - " << m_ImageController->currentImage().cols;
    }
    catch(const char* msg)
    {
        qDebug() << msg;
    }
}
