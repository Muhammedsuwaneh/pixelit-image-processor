#include "ImageController.h"
#include <QFileDialog>

static const QUrl IMAGE_URL("image://controller/current");

ImageController::ImageController(QObject *parent)
    : QObject{parent}, m_image(QImage())
{}

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

QUrl ImageController::imageSource() const
{
    return IMAGE_URL;
}

void ImageController::setProvider(ImageProvider *provider)
{
    this->m_provider = provider;
}

void ImageController::loadImage()
{
    const QString filePath = QFileDialog::getOpenFileName(nullptr, "Select Image", QString(), "Images (*.png *.jpg *.jpeg *.bmp");

    if(!filePath.isEmpty())
    {
        this->Image = cv::imread(filePath.toStdString());

        if(Image.empty()) return;

        this->m_image = matToImage(this->Image);
        this->m_provider->setImage(this->m_image);

        emit imageSourceChanged();
    }
}

void ImageController::saveImage(const QUrl &imageSource)
{

}
