#include "ImageCropController.h"
#include <QDebug>

ImageCropController::ImageCropController(ImageController* imageController, QObject *parent)
    : QObject(parent), m_ImageController(imageController)
{
    Q_ASSERT(m_ImageController);
}

void ImageCropController::cropImage()
{
    cv::Mat src = m_ImageController->editBaseImage();
    if (src.empty())
        return;

    if (m_width <= 0 || m_height <= 0)
        return;

    qDebug() << "Before resizing: " << src.rows << " - " << src.cols;

    // Clamp crop area to image bounds
    int x = std::max(0, m_x);
    int y = std::max(0, m_y);
    int w = std::min(m_width,  src.cols - x);
    int h = std::min(m_height, src.rows - y);

    if (w <= 0 || h <= 0)
        return;

    cv::Rect roi(x, y, w, h);
    cv::Mat cropped = src(roi).clone();

    this->m_ImageController->setCurrentImage(cropped);

    qDebug() << "Before resizing: " << m_ImageController->currentImage().rows << " - " << m_ImageController->currentImage().cols;
}

int ImageCropController::x() const { return m_x; }
int ImageCropController::y() const { return m_y; }
int ImageCropController::width() const { return m_width; }
int ImageCropController::height() const { return m_height; }

void ImageCropController::setX(int value)
{
    if (m_x == value) return;
    m_x = value;
    emit cropChanged();
}

void ImageCropController::setY(int value)
{
    if (m_y == value) return;
    m_y = value;
    emit cropChanged();
}

void ImageCropController::setWidth(int value)
{
    if (m_width == value) return;
    m_width = value;
    emit cropChanged();
}

void ImageCropController::setHeight(int value)
{
    if (m_height == value) return;
    m_height = value;
    emit cropChanged();
}
