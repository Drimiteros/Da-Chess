#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Board.h"

using namespace std;
using namespace sf;

class Counter
{
private:

public:
	Clock update_clock;
	int white_time = 600; // sec
	int black_time = 600;

	bool start_white_timer = false;
	bool start_black_timer = false;

	Font font;
	Text white_clock_text;
	Text black_clock_text;

	Counter();
	void count_white_time(Board& board);
	void count_black_time(Board& board);
	void draw(RenderWindow& window);
};

