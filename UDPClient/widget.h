#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui
{
class Widget;
}

class QUdpSocket;

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);
    virtual ~Widget();
private slots:
    void on_connect_clicked();
private:
    Ui::Widget *ui;
    QUdpSocket *mSocket;
};

#endif // WIDGET_H
