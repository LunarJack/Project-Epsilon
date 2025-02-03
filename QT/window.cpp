#include "window.h"
#include <QApplication>
#include <QPushButton>
#include <QProgressBar>
#include <QSlider>

Window::Window(QWidget *parent) : QWidget(parent)
{
    m_button = new QPushButton("Hello World", this);
    m_button->setGeometry(210, 10, 80, 30);
    connect(m_button, SIGNAL (clicked()), QApplication::instance(), SLOT (quit()));
    progressBar = new QProgressBar(this);
    progressBar->setRange(0, 100);
    progressBar->setValue(0);
    progressBar->setGeometry(10, 10, 180, 30);
    slider = new QSlider(this);
    slider->setOrientation(Qt::Horizontal);
    slider->setRange(0, 100);
    slider->setValue(0);
    slider->setGeometry(10, 40, 180, 30);
    QObject::connect(slider, SIGNAL (valueChanged(int)), progressBar, SLOT (setValue(int)));
}
