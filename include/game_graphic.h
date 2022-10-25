#ifndef GAME_GRAPHIC_H
#define GAME_GRAPHIC_H

#include <QOpenGLWidget>
#include <QPainter>
#include <QWheelEvent>
#include <QDebug>
#include "extern.h"

class GameGraphic : public QOpenGLWidget
{
public:
    GameGraphic(QOpenGLWidget* parent = nullptr);
    ~GameGraphic();

};


#endif // GAME_GRAPHIC_H