#ifndef WINDOWCONTROLLER_H
#define WINDOWCONTROLLER_H

#include <QObject>

class WindowController : public QObject
{
    Q_OBJECT
public:
    explicit WindowController(QObject *parent = nullptr);

signals:
};

#endif // WINDOWCONTROLLER_H
