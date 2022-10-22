#include "mainwindow.h"
#include "./ui_mainwindow.h"

Config extern_config;
WorldModel extern_wm;
GameState extern_gamestate;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFocus(); // no defualt focus on widgets

    config_handler = new ConfigHandler{ui};
    game = new Game{};
    connect(game, &Game::round_finished, this, &MainWindow::handle_round_finished);

    // just some debugging
    game->create_board();
    game->print_board();

    game->step();
    game->step();
    game->step();
    game->step();
    game->step();
    game->step();
    game->step();
    game->step();
    game->step();
    game->step();
    game->step();
    game->step();
    game->step();
    game->print_board();

}

MainWindow::~MainWindow()
{
    delete ui;
    delete config_handler;
    delete game;
}

void MainWindow::handle_round_finished()
{
    qDebug() << "finisheddddddd!!!!!";
}