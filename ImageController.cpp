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
        cv::Mat tempImage = cv::imread(filePath.toStdString());

        if(tempImage.empty()) return;

        this->m_image = matToImage(tempImage);

        emit imageChanged();
    }
}

QImage ImageController::image() const
{
    return this->m_image;
}
