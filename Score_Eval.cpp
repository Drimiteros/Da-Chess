#include "Score_Eval.h"

Score_Eval::Score_Eval()
{
	font.loadFromFile("src/Fonts/font.ttf");

	black_score_text.setFont(font);
	black_score_text.setFillColor(Color(255, 255, 255, 100));
	black_score_text.setCharacterSize(30);
	black_score_text.setPosition(850, 290);

	black_piece_advantage_text.setFont(font);
	black_piece_advantage_text.setFillColor(Color(255, 255, 255, 100));
	black_piece_advantage_text.setCharacterSize(30);
	black_piece_advantage_text.setPosition(700, 30);

	white_score_text.setFont(font);
	white_score_text.setFillColor(Color(255, 255, 255, 100));
	white_score_text.setCharacterSize(30);
	white_score_text.setPosition(850, 400);

	white_piece_advantage_text.setFont(font);
	white_piece_advantage_text.setFillColor(Color(255, 255, 255, 100));
	white_piece_advantage_text.setCharacterSize(30);
	white_piece_advantage_text.setPosition(700, 650);

	line.setSize(Vector2f(500, 3));
	line.setPosition(720, 360);
	line.setFillColor(Color(255, 255, 255, 100));
}

void Score_Eval::calculate_white_score(Board& board)
{
	white_material = 0;
	white_pawn_score = 0;
	white_queen_score = 0;
	white_bishop_score = 0;
	white_knight_score = 0;
	white_rook_score = 0;
	white_king_score = 0;

	for (int i = 0; i < 64; i++)
	{
		for (int p = 0; p < 8; p++)
			if (board.square[i].getGlobalBounds().intersects(board.white_pawn[p].getGlobalBounds())) {
				white_material++;
				white_pawn_score++;
				white_pawn_score += board.psts.whitePawnTable[i];
			}
		for (int n = 0; n < 9; n++)
			if (board.square[i].getGlobalBounds().intersects(board.white_knight[n].getGlobalBounds())) {
				white_material += 3;
				white_knight_score += 3;
				white_knight_score += board.psts.whiteKnightTable[i];
			}
		for (int b = 0; b < 9; b++)
			if (board.square[i].getGlobalBounds().intersects(board.white_bishop[b].getGlobalBounds())) {
				white_material += 3;
				white_bishop_score += 3;
				white_bishop_score += board.psts.whiteBishopTable[i];
			}
		for (int r = 0; r < 9; r++)
			if (board.square[i].getGlobalBounds().intersects(board.white_rook[r].getGlobalBounds())) {
				white_material += 5;
				white_rook_score += 5;
				white_rook_score += board.psts.whiteRookTable[i];
			}
		for (int q = 0; q < 9; q++)
			if (board.square[i].getGlobalBounds().intersects(board.white_queen[q].getGlobalBounds())) {
				white_material += 9;
				white_queen_score += 9;
				white_queen_score += board.psts.whiteQueenTable[i];
			}
	}
	total_white_score = white_pawn_score + white_knight_score + white_bishop_score + white_rook_score + white_queen_score + white_material + board.white_available_moves - 3;
	if (white_material - black_material > 0)
		white_piece_advantage_text.setString("+" + to_string(white_material - black_material));
	else
		white_piece_advantage_text.setString("");
}

void Score_Eval::calculate_black_score(Board& board)
{
	black_material = 0;
	black_pawn_score = 0;
	black_queen_score = 0;
	black_bishop_score = 0;
	black_knight_score = 0;
	black_rook_score = 0;
	black_king_score = 0;

	for (int i = 0; i < 64; i++)
	{
		for (int p = 0; p < 8; p++)
			if (board.square[i].getGlobalBounds().intersects(board.black_pawn[p].getGlobalBounds())) {
				black_material++;
				black_pawn_score++;
				black_pawn_score += board.psts.blackPawnTable[i];
			}
		for (int n = 0; n < 9; n++)
			if (board.square[i].getGlobalBounds().intersects(board.black_knight[n].getGlobalBounds())) {
				black_material += 3;
				black_knight_score += 3;
				black_knight_score += board.psts.blackKnightTable[i];
			}
		for (int b = 0; b < 9; b++)
			if (board.square[i].getGlobalBounds().intersects(board.black_bishop[b].getGlobalBounds())) {
				black_material += 3;
				black_bishop_score += 3;
				black_bishop_score += board.psts.blackBishopTable[i];
			}
		for (int r = 0; r < 9; r++)
			if (board.square[i].getGlobalBounds().intersects(board.black_rook[r].getGlobalBounds())) {
				black_material += 5;
				black_rook_score += 5;
				black_rook_score += board.psts.blackRookTable[i];
			}
		for (int q = 0; q < 9; q++)
			if (board.square[i].getGlobalBounds().intersects(board.black_queen[q].getGlobalBounds())) {
				black_material += 9;
				black_queen_score += 9;
				black_queen_score += board.psts.blackQueenTable[i];
			}
	}
	total_black_score = black_pawn_score + black_knight_score + black_bishop_score + black_rook_score + black_queen_score + black_material + board.black_available_moves - 3;
	if (black_material - white_material > 0)
		black_piece_advantage_text.setString("+" + to_string(black_material - white_material));
	else
		black_piece_advantage_text.setString("");
}

void Score_Eval::draw(RenderWindow& window, Board& board)
{
	if (board.update_score) {
		white_score_text.setString("White score: " + to_string(total_white_score));
		black_score_text.setString("Black score: " + to_string(total_black_score));
		board.update_score = false;
	}

	window.draw(white_score_text);
	window.draw(black_score_text);
	window.draw(line);
	window.draw(white_piece_advantage_text);
	window.draw(black_piece_advantage_text);
}