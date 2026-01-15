#include "ImageTextureController.h"

ImageTextureController::ImageTextureController(ImageController* imageController, QObject *parent): QObject{parent}, m_ImageController(imageController)
{
    Q_ASSERT(imageController);
}
