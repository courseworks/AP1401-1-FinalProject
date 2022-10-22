#ifndef EXTERN_H
#define EXTERN_H

#include <QString>
#include <QPoint>

using Board = QVector<QVector<int>>;

struct Config
{
    int field_cellnum;
    float field_cellwidth;

    QString broadcast_ip;
    int broadcast_port;

    QString command_ip;

    QString blueteam_name;
    int blueteam_port;
    bool blueteam_handy;

    QString redteam_name;
    int redteam_port;
    bool redteam_handy;

};

struct WorldModel
{
    Board board;
    QPoint blue_startpos;
    QPoint red_startpos;
    int blue_score;
    int red_score;
};

enum class GameState {Running = 0, Pause = 1, WitingForClients = 2};

extern Config extern_config;
extern WorldModel extern_wm;
extern GameState extern_gamestate;

#endif // EXTERN_H