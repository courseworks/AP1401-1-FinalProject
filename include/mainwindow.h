#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "extern.h"
#include "config_handler.h"

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

public slots:
    void handle_start_stop();
    void handle_reset_round();
    void handle_reset_game();
};


#endif // MAINWINDOW_H