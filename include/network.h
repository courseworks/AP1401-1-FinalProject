#ifndef NETWORK_H
#define NETWORK_H


#include <iostream>
#include <QDebug>
#include <QThread>
#include <QUdpSocket>
#include <QNetworkDatagram>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "extern.h"

class BroadCast : public QThread
{
    Q_OBJECT
public:
    BroadCast(QThread* parent = nullptr);
    ~BroadCast();

    void run() override;
    QUdpSocket* udp;

private:

    // shortcuts to extern variables
    QString& ip;
    int& port;
    Board& board;
    Tron& blue;
    Tron& red;

};


class ReceiveCommand : public QObject
{
    Q_OBJECT
public:
    ReceiveCommand(QObject* parent = nullptr);
    ~ReceiveCommand();

    QUdpSocket* blue_udp;
    QUdpSocket* red_udp;

public slots:
    void connect_to_hosts();

private:
    // shortcuts to extern variables
    QString& ip;
    int& blue_port;
    int& red_port;
    Tron& blue;
    Tron& red;

private slots:
    void handle_blue_command();
    void handle_red_command();
};


#endif // NETWORK_H