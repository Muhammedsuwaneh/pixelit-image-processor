#include "ImageTextureController.h"

ImageTextureController::ImageTextureController(ImageController* imageController, QObject *parent): QObject{parent}, m_ImageController(imageController)
{
    Q_ASSERT(imageController);
}

void ImageTextureController::adjustBrightness(int brightness)
{

}

void ImageTextureController::adjustContrast(int contrast)
{

}

void ImageTextureController::adjustSaturation(int saturation)
{

}

void ImageTextureController::adjustExposure(int exposure)
{

}

void ImageTextureController::adjustGrayScale(int grayScale)
{

}

void ImageTextureController::adjustSepia(int sepia)
{

}
