#include "Counter.h"

Counter::Counter() {
	font.loadFromFile("src/Fonts/font.ttf");
	white_clock_text.setFont(font);
	white_clock_text.setCharacterSize(30);

	black_clock_text.setFont(font);
	black_clock_text.setCharacterSize(30);
}

void Counter::count_white_time(Board& board) {
	white_clock_text.setPosition(1280 / 2 + 310 - white_clock_text.getLocalBounds().width / 2, 650);

	if (board.white_plays) {
		if (update_clock.getElapsedTime().asSeconds() >= 1) {
			white_time = white_time - 1;
			update_clock.restart();
		}
	}
	if (white_time / 60 >= 10 && white_time % 60 >= 10)
		white_clock_text.setString(to_string(white_time / 60) + ":" + to_string(white_time % 60));
	else if (white_time / 60 >= 10 && white_time % 60 < 10)
		white_clock_text.setString(to_string(white_time / 60) + ":0" + to_string(white_time % 60));
	else if (white_time / 60 < 10 && white_time % 60 >= 10)
		white_clock_text.setString("0" + to_string(white_time / 60) + ":" + to_string(white_time % 60));
	else
		white_clock_text.setString("0" + to_string(white_time / 60) + ":0" + to_string(white_time % 60));
}

void Counter::count_black_time(Board& board) {
	black_clock_text.setPosition(1280 / 2 + 310 - black_clock_text.getLocalBounds().width / 2, 30);

	if (!board.white_plays) {
		if (update_clock.getElapsedTime().asSeconds() >= 1) {
			black_time = black_time - 1;
			update_clock.restart();
		}
	}
	if (black_time / 60 >= 10 && black_time % 60 >= 10)
		black_clock_text.setString(to_string(black_time / 60) + ":" + to_string(black_time % 60));
	else if (black_time / 60 >= 10 && black_time % 60 < 10)
		black_clock_text.setString(to_string(black_time / 60) + ":0" + to_string(black_time % 60));
	else if (black_time / 60 < 10 && black_time % 60 >= 10)
		black_clock_text.setString("0" + to_string(black_time / 60) + ":" + to_string(black_time % 60));
	else
		black_clock_text.setString("0" + to_string(black_time / 60) + ":0" + to_string(black_time % 60));
}

void Counter::draw(RenderWindow& window) {
	window.draw(white_clock_text);
	window.draw(black_clock_text);
}