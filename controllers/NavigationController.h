#ifndef NAVIGATIONCONTROLLER_H
#define NAVIGATIONCONTROLLER_H

#include <QObject>
#include <QStringList>

class NavigationController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int currentActivePage READ currentActivePage WRITE setCurrentActivePage NOTIFY currentActivePageChanged)
    Q_PROPERTY(QStringList pages READ pages CONSTANT)
public:
    explicit NavigationController(QObject *parent = nullptr);

    Q_INVOKABLE int currentActivePage() const;
    Q_INVOKABLE void setCurrentActivePage(int newCurrentActivePage);

    QStringList pages() const;

signals:
    void currentActivePageChanged();
private:
    int m_currentActivePage = 0;
    QStringList m_pages;
};

#endif // NAVIGATIONCONTROLLER_H
