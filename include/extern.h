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

extern Config extern_config;
extern WorldModel extern_wm;

#endif // EXTERN_H