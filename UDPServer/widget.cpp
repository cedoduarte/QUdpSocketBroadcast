#include "widget.h"
#include "ui_widget.h"

#include <QUdpSocket>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mSocket = new QUdpSocket(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_send_clicked()
{
    mSocket->writeDatagram(ui->msg->text().toLatin1(), QHostAddress::Broadcast, ui->port->value());
}

