#include "NavigationController.h"

NavigationController::NavigationController(QObject *parent)
    : QObject{parent}
{
    this->m_pages << "zoom"
                  << "pan"
                  << "rotate"
                  << "crop"
                  << "resize"
                  << "brightness"
                  << "contrast"
                  << "saturation"
                  << "exposure"
                  << "grayScale"
                  << "sepia"
                  << "invert"
                  << "sharpen";
}

int NavigationController::currentActivePage() const
{
    return this->m_currentActivePage;
}

void NavigationController::setCurrentActivePage(int newCurrentActivePage)
{
    if (this->m_currentActivePage == newCurrentActivePage)
        return;
    this->m_currentActivePage = newCurrentActivePage;
    emit currentActivePageChanged();
}

QStringList NavigationController::pages() const
{
    return this->m_pages;
}
