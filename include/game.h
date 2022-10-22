#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <QObject>
#include <QDebug>
#include "extern.h"

class Game : public QObject
{
    Q_OBJECT

public:
    Game(QObject* parent = nullptr);
    ~Game();

    void create_board();
    void print_board();

    void reset_round();
    void reset_game();

    void step();

signals:
    void round_finished();

};

#endif // GAME_H