#include "mainwindow.h"
#include "./ui_mainwindow.h"

Config extern_config;
WorldModel extern_wm;
GameState extern_gamestate = GameState::Pause;

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

    game_graphic = new GameGraphic{};
    layout_game_graphic = new QGridLayout{ui->widget_game};
    ui->widget_game->setContentsMargins(0, 0, 0, 0);
    layout_game_graphic->setSpacing(0);
    layout_game_graphic->setContentsMargins(0, 0, 0, 0);
    layout_game_graphic->addWidget(game_graphic);

    // pushbuttons
    connect(ui->pushButton_start_stop, &QPushButton::clicked, this, &MainWindow::handle_start_stop);
    connect(ui->pushButton_resetround, &QPushButton::clicked, this, &MainWindow::handle_reset_round);
    connect(ui->pushButton_resetgame, &QPushButton::clicked, this, &MainWindow::handle_reset_game);

    // timer
    simulator_timer = new QTimer{};
    connect(simulator_timer, &QTimer::timeout, this, &MainWindow::handle_simulator_timer);
    step_time = 100;
    simulator_timer->start(step_time);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete config_handler;
    delete game;
    delete simulator_timer;
    delete game_graphic;
}

void MainWindow::handle_round_finished()
{
    simulator_timer->stop();
    ui->label_blueteam_score->setText(QString::number(extern_wm.blue.score));
    ui->label_redteam_score->setText(QString::number(extern_wm.red.score));
    game_graphic->redraw();
    game->reset_round();
    // QThread::sleep(1);
    simulator_timer->start(step_time);
}

void MainWindow::handle_start_stop()
{
    this->setFocus();
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
    game_graphic->redraw();
}

void MainWindow::handle_reset_game()
{
    ui->pushButton_start_stop->setText("Start");
    extern_gamestate = GameState::Pause;
    game->reset_game();
    game_graphic->redraw();
    ui->label_blueteam_score->setText(QString::number(extern_wm.blue.score));
    ui->label_redteam_score->setText(QString::number(extern_wm.red.score));
}

void MainWindow::handle_simulator_timer()
{
    if(extern_gamestate == GameState::Pause) return;
    simulator_timer->stop();

    ui->label_blueteam_score->setText(QString::number(extern_wm.blue.score));
    ui->label_redteam_score->setText(QString::number(extern_wm.red.score));

    ui->label_blueteam_dir->setText(dir_to_text(extern_wm.blue.dir));
    ui->label_redteam_dir->setText(dir_to_text(extern_wm.red.dir));

    game->step();
    // game->print_board();
    game_graphic->redraw();

    simulator_timer->start(step_time);
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
    int min = std::min(ui->widget_game->size().width(), ui->widget_game->size().height());
    game_graphic->setMaximumSize(min, min);
}

void MainWindow::showEvent(QShowEvent* event)
{
    // correcting gameview initial size
    int min = std::min(ui->widget_game->size().width(), ui->widget_game->size().height());
    game_graphic->setMaximumSize(min, min);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up)
        extern_wm.blue.dir = Direction::Up;
    else if(event->key() == Qt::Key_Right)
        extern_wm.blue.dir = Direction::Right;
    else if(event->key() == Qt::Key_Down)
        extern_wm.blue.dir = Direction::Down;
    else if(event->key() == Qt::Key_Left)
        extern_wm.blue.dir = Direction::Left;

    if(event->key() == Qt::Key_W)
        extern_wm.red.dir = Direction::Up;
    else if(event->key() == Qt::Key_D)
        extern_wm.red.dir = Direction::Right;
    else if(event->key() == Qt::Key_S)
        extern_wm.red.dir = Direction::Down;
    else if(event->key() == Qt::Key_A)
        extern_wm.red.dir = Direction::Left;
}