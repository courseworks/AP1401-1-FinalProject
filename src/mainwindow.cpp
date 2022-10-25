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

    game_graphic = new GameGraphic{};
    layout_game_graphic = new QGridLayout{ui->widget_game};
    ui->widget_game->setContentsMargins(0, 0, 0, 0);
    layout_game_graphic->setSpacing(0);
    layout_game_graphic->setContentsMargins(0, 0, 0, 0);
    layout_game_graphic->addWidget(game_graphic);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete config_handler;
    delete game;
    delete game_graphic;
    delete layout_game_graphic;
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