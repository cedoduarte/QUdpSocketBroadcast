#include "widget.h"
#include "ui_widget.h"

#include <QUdpSocket>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mSocket = new QUdpSocket(this);

    connect(mSocket, &QUdpSocket::readyRead, [&]()
    {
        if (mSocket->hasPendingDatagrams())
        {
            QByteArray datagram;
            datagram.resize(mSocket->pendingDatagramSize());
            mSocket->readDatagram(datagram.data(), datagram.size());
            ui->listWidget->addItem(QString::fromLatin1(datagram));
        }
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_connect_clicked()
{
    mSocket->bind(ui->port->value(), QUdpSocket::ShareAddress);
}

