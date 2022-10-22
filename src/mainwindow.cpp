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

    // pushbuttons
    connect(ui->pushButton_start_stop, &QPushButton::clicked, this, &MainWindow::handle_start_stop);
    connect(ui->pushButton_resetround, &QPushButton::clicked, this, &MainWindow::handle_reset_round);
    connect(ui->pushButton_resetgame, &QPushButton::clicked, this, &MainWindow::handle_reset_game);

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

void MainWindow::handle_start_stop()
{
    if(ui->pushButton_start_stop->text().toUpper() == "START")
    {
        ui->pushButton_start_stop->setText("Pause");
        extern_gamestate = GameState::Running;
    }
    else
    {
        ui->pushButton_start_stop->setText("Start");
        extern_gamestate = GameState::Pause;
    }
}

void MainWindow::handle_reset_round()
{
    ui->pushButton_start_stop->setText("Start");
    extern_gamestate = GameState::Pause;
}

void MainWindow::handle_reset_game()
{
    ui->pushButton_start_stop->setText("Start");
    extern_gamestate = GameState::Pause;
}