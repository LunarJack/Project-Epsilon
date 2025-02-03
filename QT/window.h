#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

class QPushButton;
class QProgressBar;
class QSlider;
class Window : public QWidget
{
    public:
        explicit Window(QWidget *parent = 0);

    private:
        QPushButton *m_button;
        QProgressBar *progressBar;
        QSlider *slider;
};

#endif // WINDOW_H
