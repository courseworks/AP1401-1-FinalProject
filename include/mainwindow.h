#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QThread>
#include "extern.h"
#include "config_handler.h"
#include "game.h"

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
    QTimer* simulator_timer;
    int step_time;

    bool is_round_finished;

public slots:
    void handle_round_finished();
    // pushbuttons
    void handle_start_stop();
    void handle_reset_round();
    void handle_reset_game();
    // timer
    void handle_simulator_timer();

};


#endif // MAINWINDOW_H