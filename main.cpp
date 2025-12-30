#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "WindowController.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

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

    engine.rootContext()->setContextProperty("WindowController", &controller);

    return app.exec();
}
