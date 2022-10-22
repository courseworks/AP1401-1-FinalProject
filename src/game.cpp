#include "game.h"

Game::Game(QObject* parent) : QObject{parent}
{
    extern_wm.blue.score = 0;
    extern_wm.red.score = 0;
}

Game::~Game()
{

}

void Game::create_board()
{
    Board& board = extern_wm.board;
    int& cell_num = extern_config.field_cellnum;
    Tron& blue = extern_wm.blue;
    Tron& red = extern_wm.red;

    board.clear();
    for(int i{}; i < cell_num; i++)
        board.push_back(QVector<int>(cell_num, 0));

    // add borders
    for(int i{}; i < cell_num; i++)
    {
        board[0][i] = -1; board[cell_num-1][i] = -1;
        board[i][0] = -1; board[i][cell_num-1] = -1;
    }

    // initialize blue tron
    blue.tail = QPoint{cell_num/2, cell_num/2 + 2};
    blue.head = blue.tail;
    board[blue.head.x()][blue.head.y()] = 1;
    blue.dir = Direction::Right; // or static_cast<Direction>(1)

    // initialize red tron
    red.tail = QPoint{cell_num/2, cell_num/2 - 2};
    red.head = red.tail;
    board[red.head.x()][red.head.y()] = 2;
    red.dir = Direction::Left; // or static_cast<Direction>(3)

}

void Game::print_board()
{
    Board& board = extern_wm.board;
    for(const auto& row : board)
    {
        for(const auto& cell : row)
            std::cout << cell << "  ";
        std::cout << std::endl;
    }
}

void Game::reset_round()
{
    create_board();
}

void Game::reset_game()
{
    create_board();
    extern_wm.blue.score = 0;
    extern_wm.red.score = 0;
}

void Game::step()
{
    Board& board = extern_wm.board;
    Tron& blue = extern_wm.blue;
    Tron& red = extern_wm.red;

    if(blue.dir == Direction::Up)
        blue.head = blue.head + QPoint{-1, 0};
    else if(blue.dir == Direction::Right)
        blue.head = blue.head + QPoint{0, 1};
    else if(blue.dir == Direction::Down)
        blue.head = blue.head + QPoint{1, 0};
    else //Left
        blue.head = blue.head + QPoint{0, -1};

    if(red.dir == Direction::Up)
        red.head = red.head + QPoint{-1, 0};
    else if(red.dir == Direction::Right)
        red.head = red.head + QPoint{0, 1};
    else if(red.dir == Direction::Down)
        red.head = red.head + QPoint{1, 0};
    else //Left
        red.head = red.head + QPoint{0, -1};

    bool is_finished = false;
    if(blue.head == red.head)
    {
        blue.score++; red.score++;
        is_finished = true;
        return;
    }
    if(board[blue.head.x()][blue.head.y()] != 0)
    {
        red.score++;
        is_finished = true;
    }
    if(board[red.head.x()][red.head.y()] != 0)
    {
        blue.score++;
        is_finished = true;
    }

    board[blue.head.x()][blue.head.y()] = 1;
    board[red.head.x()][red.head.y()] = 2;  

    if(is_finished) emit round_finished();  
}