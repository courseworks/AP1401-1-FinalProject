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

private:
    // shortcuts to extern variables
    Board& board;
    int& cell_num;
    Tron& blue;
    Tron& red;

    QPainter* painter;
    double scale_ratio;

private slots:
    void paintGL() override;
    void initializeGL() override;
    void wheelEvent(QWheelEvent * event) override;

};


#endif // GAME_GRAPHIC_H