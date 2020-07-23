#ifndef SLIDINGMICROBAR_H
#define SLIDINGMICROBAR_H

#include <QWidget>
#include <QtUiPlugin/QDesignerExportWidget>
#include <QDebug>
#include <QPushButton>
#include <QMouseEvent>

namespace Ui {
class SlidingMicroBar;
}

class QDESIGNER_WIDGET_EXPORT SlidingMicroBar : public QWidget
{
    Q_OBJECT

public:
    explicit SlidingMicroBar(QWidget *parent = 0);
    ~SlidingMicroBar();
    float m_location;


private:
    Ui::SlidingMicroBar *ui;
    QPushButton * m_button;
    bool m_button_pressed;
    int m_statue;
    int m_pox_x;

protected:
    virtual void resizeEvent(QResizeEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);

signals:
    void location_changed(int state, int distence);

private slots:
    void button_clicked();
};

#endif // SLIDINGMICROBAR_H
