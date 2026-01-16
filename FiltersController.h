#ifndef FILTERSCONTROLLER_H
#define FILTERSCONTROLLER_H

#include <QObject>
#include "ImageController.h"
#include <opencv2/opencv.hpp>

class FiltersController : public QObject
{
    Q_OBJECT
public:
    explicit FiltersController(ImageController* imageController, QObject *parent = nullptr);
    Q_INVOKABLE void applyFilter(QString filter);
signals:
private:
    void ApplyGrayFilter();
    void ApplySepia();
    void ApplyGaussianBlur();
    void ApplySharpen();
    void ApplyEdgeDetection();
    ImageController* m_ImageController;
};

#endif // FILTERSCONTROLLER_H
