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

    m_originalImage = img.clone();
    m_currentImage  = img.clone();

    m_undoStack.clear();
    m_redoStack.clear();

    m_qimage = matToImage(m_currentImage);
    emit imageChanged();
    emit originalImageChanged();
}

void ImageController::setCurrentImage(const cv::Mat& image)
{
    if (image.empty())
        return;

    m_currentImage = image.clone();
    m_qimage = matToImage(m_currentImage);

    emit imageChanged();
}

void ImageController::commit()
{
    if (m_currentImage.empty())
        return;

    m_undoStack.push_back(m_currentImage.clone());

    m_redoStack.clear();

    m_originalImage = m_currentImage.clone();
    emit originalImageChanged();
}

void ImageController::undo()
{
    if (m_undoStack.empty())
        return;

    m_redoStack.push_back(m_currentImage.clone());

    m_currentImage = m_undoStack.back().clone();
    m_undoStack.pop_back();

    m_qimage = matToImage(m_currentImage);
    emit imageChanged();
}

void ImageController::redo()
{
    if (m_redoStack.empty())
        return;

    m_undoStack.push_back(m_currentImage.clone());

    m_currentImage = m_redoStack.back().clone();
    m_redoStack.pop_back();

    m_qimage = matToImage(m_currentImage);
    emit imageChanged();
}

void ImageController::restoreToDefault()
{
    if (m_originalImage.empty())
        return;

    m_undoStack.clear();
    m_redoStack.clear();

    m_currentImage = m_originalImage.clone();
    m_qimage = matToImage(m_currentImage);

    emit imageChanged();
}

void ImageController::saveImage()
{
    if (m_currentImage.empty())
        return;

    const QString filePath =
        QFileDialog::getSaveFileName(nullptr,
                                     "Save Image",
                                     QString(),
                                     "Images (*.png *.jpg *.jpeg *.bmp)");

    if (filePath.isEmpty())
        return;

    cv::imwrite(filePath.toStdString(), m_currentImage);
}

QImage ImageController::image() const
{
    return m_qimage;
}

cv::Mat ImageController::originalImage() const
{
    return m_originalImage;
}

cv::Mat ImageController::currentImage() const
{
    return m_currentImage;
}

