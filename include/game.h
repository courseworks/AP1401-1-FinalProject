#ifndef GAME_H
#define GAME_H

#include <QObject>

class Game : public QObject
{
    Q_OBJECT

public:
    Game(QObject* parent = nullptr);
    ~Game();

};

#endif // GAME_H