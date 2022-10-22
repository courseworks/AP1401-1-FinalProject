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

    void redraw();

private:
    QPainter* painter;
    double scale_ratio;

    QPointF CVT(int i, int j) {return QPointF{j*cell_width - (cell_width*cell_num)/2, i*cell_width - (cell_width*cell_num)/2};}

    Board& board;
    int& cell_num;
    float& cell_width;

protected:
    void paintGL() override;
    void initializeGL() override;

private:
    void resizeGL(int w, int h) override;
    void wheelEvent ( QWheelEvent * event ) override;

};


#endif // GAME_GRAPHIC_H