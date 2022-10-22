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
    game->reset_game();
    connect(game, &Game::round_finished, this, &MainWindow::handle_round_finished);
    is_round_finished = false;
    // ui->label_blueteam_score->setText(QString::number(extern_wm.blue.score));
    // ui->label_redteam_score->setText(QString::number(extern_wm.red.score));

    // pushbuttons
    connect(ui->pushButton_start_stop, &QPushButton::clicked, this, &MainWindow::handle_start_stop);
    connect(ui->pushButton_resetround, &QPushButton::clicked, this, &MainWindow::handle_reset_round);
    connect(ui->pushButton_resetgame, &QPushButton::clicked, this, &MainWindow::handle_reset_game);

    // timer
    simulator_timer = new QTimer{};
    connect(simulator_timer, &QTimer::timeout, this, &MainWindow::handle_simulator_timer);
    step_time = 500;
    simulator_timer->start(step_time);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete config_handler;
    delete game;
    delete simulator_timer;
}

void MainWindow::handle_round_finished()
{
    simulator_timer->stop();
    game->reset_round();
    ui->label_blueteam_score->setText(QString::number(extern_wm.blue.score));
    ui->label_redteam_score->setText(QString::number(extern_wm.red.score));
    // QThread::sleep(1);
    simulator_timer->start(step_time);
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
    game->reset_round();
}

void MainWindow::handle_reset_game()
{
    ui->pushButton_start_stop->setText("Start");
    extern_gamestate = GameState::Pause;
    game->reset_game();
}

void MainWindow::handle_simulator_timer()
{
    if(extern_gamestate == GameState::Pause) return;
    simulator_timer->stop();

    ui->label_blueteam_dir->setText(dir_to_text(extern_wm.blue.dir));
    ui->label_redteam_dir->setText(dir_to_text(extern_wm.red.dir));

    game->step();
    // game->print_board();

    simulator_timer->start(step_time);
}