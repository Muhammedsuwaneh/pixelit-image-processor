#ifndef FILTERSCONTROLLER_H
#define FILTERSCONTROLLER_H

#include <QObject>
#include <QString>
#include "ImageController.h"

class FiltersController : public QObject
{
    Q_OBJECT
public:
    explicit FiltersController(ImageController* imageController, QObject *parent = nullptr);

    Q_INVOKABLE void applyFilter(const QString& filter);

private:
    void applyGrayFilter();
    void applySepia();
    void applyGaussianBlur();
    void applySharpen();
    void applyEdgeDetection();

private:
    ImageController* m_ImageController = nullptr;
};

#endif // FILTERSCONTROLLER_H
