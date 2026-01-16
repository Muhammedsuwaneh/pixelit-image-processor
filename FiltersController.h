#ifndef FILTERSCONTROLLER_H
#define FILTERSCONTROLLER_H

#include <QObject>

class FiltersController : public QObject
{
    Q_OBJECT
public:
    explicit FiltersController(QObject *parent = nullptr);

signals:
};

#endif // FILTERSCONTROLLER_H
