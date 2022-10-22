#ifndef EXTERN_H
#define EXTERN_H

#include <QString>

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

};

enum class GameState {Running = 0, Pause = 1, WitingForClients = 2};

extern Config extern_config;
extern WorldModel extern_wm;
extern GameState extern_gamestate;

#endif // EXTERN_H