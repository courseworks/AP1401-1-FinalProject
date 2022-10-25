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
}

MainWindow::~MainWindow()
{
    delete ui;
    delete config_handler;
    delete game;
}