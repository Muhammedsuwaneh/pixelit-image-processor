#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "WindowController.h"
#include "NavigationController.h"
#include "ImageController.h"
#include "ImageProvider.h"
#include "ImageScaleController.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

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
    ImageScaleController imageScaleController;

    engine.addImageProvider("imageController", new ImageProvider());
    engine.rootContext()->setContextProperty("imageController", &imageController);

    engine.rootContext()->setContextProperty("WindowController", &controller);
    engine.rootContext()->setContextProperty("NavigationController", &navigationController);

    engine.rootContext()->setContextProperty("ImageScaleController", &imageScaleController);

    return app.exec();
}
