#ifndef NETWORK_H
#define NETWORK_H


#include <iostream>
#include <QDebug>
#include <QThread>
#include <QUdpSocket>
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


#endif // NETWORK_H