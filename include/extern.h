#ifndef EXTERN_H
#define EXTERN_H

#include <QString>
#include <QPoint>

using Board = QVector<QVector<int>>;

// config
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

// worldmodel
enum class Direction {Up = 0, Right = 1, Down = 2, Left = 3};
struct Tron
{
    QPoint head;
    QPoint tail;
    Direction dir;
    int score;
};

inline QString dir_to_text(Direction dir)
{
    if(dir == Direction::Up)
        return "Up";
    if(dir == Direction::Right)
        return "Right";
    if(dir == Direction::Down)
        return "Down";
    // left
        return "Left";
}

struct WorldModel
{
    Board board;
    Tron blue;
    Tron red;
};

// game state
enum class GameState {Running = 0, Pause = 1, WitingForClients = 2};

extern Config extern_config;
extern WorldModel extern_wm;
extern GameState extern_gamestate;

#endif // EXTERN_H