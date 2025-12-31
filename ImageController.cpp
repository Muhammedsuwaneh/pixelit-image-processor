#include "ImageController.h"
#include <QFileDialog>

ImageController::ImageController(QObject *parent)
    : QObject{parent}, m_imageSource(QUrl())
{}

QUrl ImageController::imageSource() const
{
    return this->m_imageSource;
}

void ImageController::setImageSource(const QUrl &newImageSource)
{
    if (this->m_imageSource == newImageSource)
        return;
    this->m_imageSource = newImageSource;
    emit imageSourceChanged();
}

void ImageController::loadImage()
{
    const QString filePath = QFileDialog::getOpenFileName(nullptr, "Select Image", QString(), "Images (*.png *.jpg *.jpeg *.bmp");


    if(!filePath.isEmpty())
    {
        this->m_imageSource = QUrl::fromLocalFile(filePath);
        emit imageSourceChanged();
    }
}

void ImageController::saveImage(const QUrl &imageSource)
{

}
