#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Get_Mouse_Cursor
{
private:

public:
	RectangleShape cursor;

	bool is_left_clicking;
	bool is_right_clicking;

	Get_Mouse_Cursor();
	void set_position(RenderWindow& window);
	void set_click();
	void draw(RenderWindow& window);
};

