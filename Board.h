#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include "Get_Mouse_Cursor.h"
#include "Sounds.h"

using namespace std;
using namespace sf;

class Board
{
private:
	int square_size = 80;
	int white_queen_count = 1;
	int black_queen_count = 1;
	int get_white_pawn_square = -1;
	int old_white_pawn_square = -1;
	int get_white_knight_square = -1;
	int old_white_knight_square = -1;
	int get_white_rook_square = -1;
	int old_white_rook_square = -1;
	int get_white_queen_square = -1;
	int old_white_queen_square = -1;
	int get_white_bishop_square = -1;
	int old_white_bishop_square = -1;
	int get_white_king_square = -1;
	int old_white_king_square = -1;
	int get_black_pawn_square = -1;
	int old_black_pawn_square = -1;
	int get_black_knight_square = -1;
	int old_black_knight_square = -1;
	int get_black_rook_square = -1;
	int old_black_rook_square = -1;
	int get_black_queen_square = -1;
	int old_black_queen_square = -1;
	int get_black_bishop_square = -1;
	int old_black_bishop_square = -1;
	int get_black_king_square = -1;
	int old_black_king_square = -1;

	string white_active_type;
	string black_active_type;
	string cpu_black_active_type = "black_pawn";

	Font font;
	Text square_number[64];
	bool is_square_occupied_with_white[64] = { 
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 
		1, 1, 1, 1, 1, 1, 1, 1, 
		1, 1, 1, 1, 1, 1, 1, 1
	};
	bool is_square_occupied_with_black[64] = {
		1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0
	};
	bool has_white_king_moved = false;
	bool has_black_king_moved = false;
	bool has_right_white_rook_moved = false;
	bool has_left_white_rook_moved = false;
	bool has_right_black_rook_moved = false;
	bool has_left_black_rook_moved = false;

	Texture white_piece_texture[6];
	Texture black_piece_texture[6];

public:
	struct PSTs {
		int whitePawnTable[64] = {
			0,  0,  0,  0,  0,  0,  0,  0,
			50, 50, 50, 50, 50, 50, 50, 50,
			10, 10, 20, 30, 30, 20, 10, 10,
			5,  5, 10, 25, 25, 10,  5,  5,
			0,  0,  0, 20, 20,  0,  0,  0,
			5, -5,-10,  0,  0,-10, -5,  5,
			5, 10, 10,-20,-20, 10, 10,  5,
			0,  0,  0,  0,  0,  0,  0,  0
		};
		int whiteKnightTable[64] = {
			-50,-40,-30,-30,-30,-30,-40,-50,
			-40,-20,  0,  5,  5,  0,-20,-40,
			-30,  5, 10, 15, 15, 10,  5,-30,
			-30,  0, 15, 20, 20, 15,  0,-30,
			-30,  5, 15, 20, 20, 15,  5,-30,
			-30,  0, 10, 15, 15, 10,  0,-30,
			-40,-20,  0,  0,  0,  0,-20,-40,
			-50,-40,-30,-30,-30,-30,-40,-50
		};
		int whiteBishopTable[64] = {
			-20,-10,-10,-10,-10,-10,-10,-20,
			-10,  5,  0,  0,  0,  0,  5,-10,
			-10, 10, 10, 10, 10, 10, 10,-10,
			-10,  0, 10, 10, 10, 10,  0,-10,
			-10,  5,  5, 10, 10,  5,  5,-10,
			-10,  0,  5, 10, 10,  5,  0,-10,
			-10,  0,  0,  0,  0,  0,  0,-10,
			-20,-10,-10,-10,-10,-10,-10,-20
		};
		int whiteRookTable[64] = {
			 0,  0,  0,  5,  5,  0,  0,  0,
			-5,  0,  0,  0,  0,  0,  0, -5,
			-5,  0,  0,  0,  0,  0,  0, -5,
			-5,  0,  0,  0,  0,  0,  0, -5,
			-5,  0,  0,  0,  0,  0,  0, -5,
			-5,  0,  0,  0,  0,  0,  0, -5,
			 5, 10, 10, 10, 10, 10, 10,  5,
			 0,  0,  0,  0,  0,  0,  0,  0
		};
		int whiteQueenTable[64] = {
			-20,-10,-10, -5, -5,-10,-10,-20,
			-10,  0,  5,  0,  0,  0,  0,-10,
			-10,  5,  5,  5,  5,  5,  0,-10,
			 -5,  0,  5,  5,  5,  5,  0, -5,
			  0,  0,  5,  5,  5,  5,  0, -5,
			-10,  0,  5,  5,  5,  5,  0,-10,
			-10,  0,  0,  0,  0,  0,  0,-10,
			-20,-10,-10, -5, -5,-10,-10,-20
		};
		int whiteKingMidTable[64] = {
			-30,-40,-40,-50,-50,-40,-40,-30,
			-30,-40,-40,-50,-50,-40,-40,-30,
			-30,-40,-40,-50,-50,-40,-40,-30,
			-30,-40,-40,-50,-50,-40,-40,-30,
			-20,-30,-30,-40,-40,-30,-30,-20,
			-10,-20,-20,-20,-20,-20,-20,-10,
			 20, 20,  0,  0,  0,  0, 20, 20,
			 20, 30, 10,  0,  0, 10, 30, 20
		};
		int whiteKingEndTable[64] = {
			-50,-40,-30,-20,-20,-30,-40,-50,
			-30,-20,-10,  0,  0,-10,-20,-30,
			-30,-10, 20, 30, 30, 20,-10,-30,
			-30,-10, 30, 40, 40, 30,-10,-30,
			-30,-10, 30, 40, 40, 30,-10,-30,
			-30,-10, 20, 30, 30, 20,-10,-30,
			-30,-30,  0,  0,  0,  0,-30,-30,
			-50,-30,-30,-30,-30,-30,-30,-50
		};

		int blackPawnTable[64];
		int blackKnightTable[64];
		int blackBishopTable[64];
		int blackRookTable[64];
		int blackQueenTable[64];
		int blackKingMidTable[64];
		int blackKingEndTable[64];

		PSTs() {
			for (int i = 0; i < 64; i++) {
				int mirror = 63 - i;
				blackPawnTable[i] = whitePawnTable[mirror];
				blackKnightTable[i] = whiteKnightTable[mirror];
				blackBishopTable[i] = whiteBishopTable[mirror];
				blackRookTable[i] = whiteRookTable[mirror];
				blackQueenTable[i] = whiteQueenTable[mirror];
				blackKingMidTable[i] = whiteKingMidTable[mirror];
				blackKingEndTable[i] = whiteKingEndTable[mirror];
			}
		}
	};
	PSTs psts;

	int white_available_moves = 0;
	int black_available_moves = 0;

	int last_moved_pawn_square = -1;
	bool last_move_was_double_pawn = false;
	string last_moved_pawn_color = "";

	bool white_plays = true;
	bool update_score = true;

	RectangleShape square[64];

	Sprite white_king;
	Sprite white_queen[9];
	Sprite white_knight[10];
	Sprite white_bishop[10];
	Sprite white_rook[10];
	Sprite white_pawn[8];
	Sprite black_king;
	Sprite black_queen[9];
	Sprite black_knight[10];
	Sprite black_bishop[10];
	Sprite black_rook[10];
	Sprite black_pawn[8];

	Sounds sounds;

	Board();
	void get_white_move_count();
	void get_black_move_count();
	bool get_white_available_paths(string& piece_type, int& target_square_id, int piece_id);
	bool get_black_available_paths(string& piece_type, int& target_square_id, int piece_id);
	void move_white_piece(Get_Mouse_Cursor& get_mouse_cursor);
	void move_black_piece(Get_Mouse_Cursor& get_mouse_cursor);
	void remove_piece(string attack_team);
	void draw(RenderWindow& window);
};

