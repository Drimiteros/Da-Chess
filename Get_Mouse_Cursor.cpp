#include "Get_Mouse_Cursor.h"

Get_Mouse_Cursor::Get_Mouse_Cursor()
{
	cursor.setSize(Vector2f(10, 10));
	cursor.setFillColor(Color::Red);
}

void Get_Mouse_Cursor::set_position(RenderWindow& window)
{
	cursor.setPosition(window.mapPixelToCoords(Vector2i(Mouse::getPosition(window).x, Mouse::getPosition(window).y)));
}

void Get_Mouse_Cursor::set_click()
{
	if (Mouse::isButtonPressed(Mouse::Left))
		is_left_clicking = true;
	else
		is_left_clicking = false;
	if (Mouse::isButtonPressed(Mouse::Right))
		is_right_clicking = true;
	else
		is_right_clicking = false;
}

void Get_Mouse_Cursor::draw(RenderWindow& window)
{
	window.draw(cursor);
}