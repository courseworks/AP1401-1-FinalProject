#include "network.h"


BroadCast::BroadCast(QThread* parent) : QThread{parent},
    ip{extern_config.broadcast_ip}, port{extern_config.broadcast_port}, board{extern_wm.board}, blue{extern_wm.blue}, red{extern_wm.red}
{
    udp = new QUdpSocket{};
}

BroadCast::~BroadCast()
{
    delete udp;
}

void BroadCast::run()
{
    QJsonObject main_json;
    main_json.insert("game_state", QJsonValue::fromVariant(state_to_text(extern_gamestate)));

    main_json.insert("1", QJsonValue::fromVariant(extern_config.blueteam_name));
    main_json.insert("2", QJsonValue::fromVariant(extern_config.redteam_name));

    QJsonArray blue_tail;
    blue_tail.push_back(blue.tail.x());
    blue_tail.push_back(blue.tail.y());
    main_json.insert("1_tail", blue_tail);
    QJsonArray red_tail;
    red_tail.push_back(red.tail.x());
    red_tail.push_back(red.tail.y());
    main_json.insert("2_tail", red_tail);

    main_json.insert("1_score", QJsonValue::fromVariant(blue.score));
    main_json.insert("2_score", QJsonValue::fromVariant(red.score));

    // QJsonArray board_array;
    // for(const auto& row : board)
    // {
    //     QJsonArray row_array;
    //     for(const auto& cell : row)
    //         row_array.push_back(cell);
    //     board_array.push_back(row_array);
    // }
    // main_json.insert("board", board_array);

    QJsonDocument doc(main_json);
    QByteArray dgram = doc.toJson(QJsonDocument::Compact);
    
    // std::cout << dgram.toStdString() << std::endl;
    auto ret = udp->writeDatagram(dgram.data(), dgram.size(), QHostAddress{ip}, 1234);
    // qDebug() << ret << dgram.size();
}