#ifndef IMAGESCALECONTROLLER_H
#define IMAGESCALECONTROLLER_H

#include <QObject>

class ImageScaleController : public QObject
{
    Q_OBJECT
public:
    explicit ImageScaleController(QObject *parent = nullptr);

signals:
};

#endif // IMAGESCALECONTROLLER_H
