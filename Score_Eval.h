#pragma once
#include <iostream>
#include "Board.h"

using namespace std;

class Score_Eval
{
private:
	int white_material = 0;
	int total_white_score = 0;
	int white_pawn_score = 0;
	int white_queen_score = 0;
	int white_bishop_score = 0;
	int white_knight_score = 0;
	int white_rook_score = 0;
	int white_king_score = 0;

	int black_material = 0;
	int total_black_score = 0;
	int black_pawn_score = 0;
	int black_queen_score = 0;
	int black_bishop_score = 0;
	int black_knight_score = 0;
	int black_rook_score = 0;
	int black_king_score = 0;

	Font font;
	Text white_score_text;
	Text white_piece_advantage_text;
	Text black_score_text;
	Text black_piece_advantage_text;

	RectangleShape line;

public:
	Score_Eval();
	void calculate_white_score(Board& board);
	void calculate_black_score(Board& board);
	void draw(RenderWindow& window, Board& board);
};

