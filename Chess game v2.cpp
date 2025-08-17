#include <iostream>
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Get_Mouse_Cursor.h"
#include "Score_Eval.h"
#include "Counter.h"

using namespace std;
using namespace sf;

int width = 1280;
int height = 720;
RenderWindow window(VideoMode(width, height), "Chess");
Event event;

Get_Mouse_Cursor get_mouse_cursor;
Board board;
Score_Eval score_eval;
Counter counter;

void window_events()
{
    while (window.pollEvent(event))
    {
        if (event.type == Event::Closed)
            window.close();
    }
}

void update_logic()
{
    board.move_white_piece(get_mouse_cursor);
    board.move_black_piece(get_mouse_cursor);
    board.get_white_move_count();
    board.get_black_move_count();

    score_eval.calculate_white_score(board);
    score_eval.calculate_black_score(board);

    counter.count_white_time(board);
    counter.count_black_time(board);

    get_mouse_cursor.set_position(window);
    get_mouse_cursor.set_click();
}

void draw_layer()
{
    window.clear(Color(43, 43, 43));

    board.draw(window);
    get_mouse_cursor.draw(window);
    score_eval.draw(window, board);
    counter.draw(window);

    window.display();
}

int main()
{
    while (window.isOpen())
    {
        window_events();
        update_logic();
        draw_layer();
    }
}