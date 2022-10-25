#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QThread>
#include "extern.h"
#include "config_handler.h"
#include "game.h"
#include "game_graphic.h"

// forward declaration
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    ConfigHandler* config_handler;
    Game* game;

    GameGraphic* game_graphic;
    QGridLayout* layout_game_graphic;

private slots:
    void resizeEvent(QResizeEvent* event) override;
    void showEvent(QShowEvent* event) override;

};


#endif // MAINWINDOW_H