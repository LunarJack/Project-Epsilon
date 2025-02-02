#include <QPushButton>
#include "window.h"

Window::Window(QWidget *parent) : QWidget(parent)
{
    m_button = new QPushButton("Hello World", this);
    m_button->setGeometry(10, 10, 80, 30);
}
