#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "controllers/WindowController.h"
#include "controllers/NavigationController.h"
#include "controllers/ImageController.h"
#include "utilities/ImageProvider.h"
#include "controllers/ImageScaleController.h"
#include "controllers/ImageRotationController.h"
#include "controllers/ImageTextureController.h"
#include "controllers/FiltersController.h"
#include "controllers/ImageResizeController.h"
#include "controllers/ImageCropController.h"
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    app.setWindowIcon(QIcon(":/assets/logo.ico"));

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("PixelItApp", "Main");

    if(engine.rootObjects().isEmpty()) return -1;

    QWindow *window = qobject_cast<QWindow*>(engine.rootObjects().first());
    WindowController controller(window);
    NavigationController navigationController;
    ImageController imageController;

    engine.addImageProvider("controller", new ImageProvider(&imageController));
    engine.rootContext()->setContextProperty("imageController", &imageController);

    engine.rootContext()->setContextProperty("WindowController", &controller);
    engine.rootContext()->setContextProperty("NavigationController", &navigationController);

    auto imageScaleController = new ImageScaleController(&imageController, &engine);
    auto imageResizeController = new ImageResizeController(&imageController, &engine);
    auto imageRotationController = new ImageRotationController(&imageController, &engine);
    auto imageTextureController = new ImageTextureController(&imageController, &engine);
    auto filtersController = new FiltersController(&imageController, &engine);
    auto imageCropController = new ImageCropController(&imageController, &engine);

    engine.rootContext()->setContextProperty("ImageScaleController", imageScaleController);
    engine.rootContext()->setContextProperty("ImageResizeController", imageResizeController);
    engine.rootContext()->setContextProperty("ImageRotationController", imageRotationController);
    engine.rootContext()->setContextProperty("ImageTextureController", imageTextureController);
    engine.rootContext()->setContextProperty("FiltersController", filtersController);
    engine.rootContext()->setContextProperty("ImageCropController", imageCropController);

    return app.exec();
}
