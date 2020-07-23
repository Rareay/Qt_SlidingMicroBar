#include "slidingmicrobar.h"
#include "ui_slidingmicrobar.h"

SlidingMicroBar::SlidingMicroBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SlidingMicroBar)
{
    ui->setupUi(this);
    this->setMinimumHeight(20);

    m_button = new QPushButton(this);
    m_button->setStyleSheet("border-image: url(:/bar1.png);");
    m_button->setMaximumWidth(7);
    m_button->setMaximumHeight(15);

    m_button_pressed = false;

    m_location = 0.5;
    m_statue = 0;

    connect(m_button, SIGNAL(pressed()), this, SLOT(button_clicked()));
}

SlidingMicroBar::~SlidingMicroBar()
{
    delete ui;
}

void SlidingMicroBar::resizeEvent(QResizeEvent *event)
{
    float x = m_location * ((float)this->geometry().width() - 14) + 7;
    float y = (this->geometry().height() + ui->label->height())/2 - m_button->height();
    m_button->move((int)x, (int)y);
}

void SlidingMicroBar::mouseReleaseEvent(QMouseEvent *event)
{
    m_button_pressed = false;
    m_statue = 0; // released
}

void SlidingMicroBar::mouseMoveEvent(QMouseEvent *event)
{
    int pos = event->x();
    if (m_button_pressed == true) {
        int distance = pos - m_pox_x;
        int x;
        int l = this->geometry().width() - 14;
        if (pos >= 7) {
            x = (pos - 7) % l + 7;
        } else {
            x = l - (7 - pos) % l + 7;
        }
        int y = (this->geometry().height() + ui->label->height())/2 - m_button->height();
        m_button->move(x, y);
        emit location_changed(m_statue, distance);
        if (m_statue == 1) {
            m_statue = 2;
            //m_pox_x = pos;
        }
    }

}


void SlidingMicroBar::button_clicked()
{
    m_button_pressed = true;
    m_statue = 1; // pressed
    m_pox_x = m_button->x();
}
