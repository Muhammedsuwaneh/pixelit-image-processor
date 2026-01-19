#include "NavigationController.h"

NavigationController::NavigationController(QObject *parent)
    : QObject{parent}
{
    this->m_pages << "Zoom"
                  << "Rotate"
                  << "Crop"
                  << "Resize"
                  << "Filters"
                  << "Brightness"
                  << "Contrast"
                  << "Saturation"
                  << "Exposure"
                  << "Gray Scale"
                  << "Sepia"
                  << "Invert"
                  << "Sharpen";
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
