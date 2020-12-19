#include <utility>
#include <conio.h>
#include "snake.h"


Snake::Snake() {
    snake_head_x = 0;
    snake_head_y = 0;

    snake_tail_x[999] = {};
    snake_tail_y[999] = {};

    head_figure = char(254);

    length = 0;

    last_move = ' ';
}

Snake::~Snake() {}

void Snake::initialize() {
    snake_head_x = 10;
    snake_head_y = 10;
}

void Snake::set_tail() {
    snake_tail_x[0] = snake_head_x;
    snake_tail_y[0] = snake_head_y;

    for (unsigned short l = 0; l < length; l++) {
        std::swap(snake_tail_x[l], snake_tail_x[l + 1]);
        std::swap(snake_tail_y[l], snake_tail_y[l + 1]);
    }
}

//this is the whole movement logic for the snake
void Snake::set_head() {
    if (_kbhit()) {
        char move = _getch();
        switch (move) {
        case 'w':
            if (last_move != 's') {
                snake_head_y--;
                last_move = move;
            }
            else { last_move_function(); }
            break;
        case 'a':
            if (last_move != 'd') {
                snake_head_x--;
                last_move = move;
            }
            else { last_move_function(); }
            break;
        case 's':
            if (last_move != 'w') {
                snake_head_y++;
                last_move = move;
            }
            else { last_move_function(); }
            break;
        case 'd':
            if (last_move != 'a') {
                snake_head_x++;
                last_move = move;
            }
            else { last_move_function(); }
            break;
        }
    }
    else { last_move_function(); }
}

void Snake::last_move_function() {
    switch (last_move) {
    case 'w':
        snake_head_y--;
        break;
    case 'a':
        snake_head_x--;
        break;
    case 's':
        snake_head_y++;
        break;
    case 'd':
        snake_head_x++;
        break;
    }
}

void Snake::set_length() {
    length++;
}

void Snake::get_head(unsigned short* head_x, unsigned short* head_y) {
    *head_x = snake_head_x;
    *head_y = snake_head_y;
}

char Snake::get_tail_figure() {
    return head_figure;
}

char Snake::get_head_figure() {
    return head_figure;
}

unsigned short Snake::get_length() {
    return length;
}

void Snake::get_tail(unsigned short *x, unsigned short *y){
    *x = snake_tail_x[*x];
    *y = snake_tail_x[*y];
}

