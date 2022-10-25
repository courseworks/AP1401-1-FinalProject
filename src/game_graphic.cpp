#include "game_graphic.h"



GameGraphic::GameGraphic(QOpenGLWidget* parent) : QOpenGLWidget{parent},
    board{extern_wm.board}, cell_num{extern_config.field_cellnum}, blue{extern_wm.blue}, red{extern_wm.red}, scale_ratio{1}
{
    painter = new QPainter{};
}

GameGraphic::~GameGraphic()
{
    delete painter;
}

void GameGraphic::paintGL()
{
    painter->begin(this);
    painter->translate(width() / 2, height() / 2); // bring the reference coordinate to the middle

    painter->scale(scale_ratio, -scale_ratio);


    painter->end();
}

void GameGraphic::initializeGL()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void GameGraphic::wheelEvent(QWheelEvent * event)
{
    int delta = event->angleDelta().x() + event->angleDelta().y();
    if (delta < 0)
        scale_ratio +=0.01;
    else if (delta > 0)
        scale_ratio -=0.01;

    if (scale_ratio <= 0)
        scale_ratio = 0.01;
    update();
}