#include "NavigationController.h"

NavigationController::NavigationController(QObject *parent)
    : QObject{parent}
{
    this->m_pages << "Zoom in/out"
                  << "Pan"
                  << "Rotate"
                  << "Crop"
                  << "Resize"
                  << "Brightness"
                  << "Contrast"
                  << "Saturation"
                  << "Gray Scale"
                  << "Sepia"
                  << "Invert"
                  << "Blue"
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
