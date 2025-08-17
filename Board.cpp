#include "Board.h"

Board::Board()
{
	font.loadFromFile("src/Fonts/font.ttf");
	for (int i = 0; i < 64; i++)
	{
		int x = i % 8;
		int y = i / 8;

		square[i].setSize(Vector2f(square_size, square_size));
		square[i].setFillColor(Color::White);
		square[i].setOrigin(square[i].getSize().x / 2, square[i].getSize().y / 2);
		square[i].setPosition(80 + (x * square_size), 80 + (y * square_size));

		square_number[i].setFont(font);
		square_number[i].setCharacterSize(15);
		square_number[i].setString(to_string(i));
		square_number[i].setPosition(square[i].getPosition());

		if ((x + y) % 2 == 1)
			square[i].setFillColor(Color(220, 255, 255));
		else
			square[i].setFillColor(Color(70, 152, 255));
	}

	white_piece_texture[0].loadFromFile("src/Textures/white-bishop.png");
	white_piece_texture[0].setSmooth(true);
	white_piece_texture[1].loadFromFile("src/Textures/white-knight.png");
	white_piece_texture[1].setSmooth(true);
	white_piece_texture[2].loadFromFile("src/Textures/white-queen.png");
	white_piece_texture[2].setSmooth(true);
	white_piece_texture[3].loadFromFile("src/Textures/white-king.png");
	white_piece_texture[3].setSmooth(true);
	white_piece_texture[4].loadFromFile("src/Textures/white-rook.png");
	white_piece_texture[4].setSmooth(true);
	white_piece_texture[5].loadFromFile("src/Textures/white-pawn.png");
	white_piece_texture[5].setSmooth(true);
	black_piece_texture[0].loadFromFile("src/Textures/black-bishop.png");
	black_piece_texture[0].setSmooth(true);
	black_piece_texture[1].loadFromFile("src/Textures/black-knight.png");
	black_piece_texture[1].setSmooth(true);
	black_piece_texture[2].loadFromFile("src/Textures/black-queen.png");
	black_piece_texture[2].setSmooth(true);
	black_piece_texture[3].loadFromFile("src/Textures/black-king.png");
	black_piece_texture[3].setSmooth(true);
	black_piece_texture[4].loadFromFile("src/Textures/black-rook.png");
	black_piece_texture[4].setSmooth(true);
	black_piece_texture[5].loadFromFile("src/Textures/black-pawn.png");
	black_piece_texture[5].setSmooth(true);

	//DEFINE PAWNS
	white_king.setTexture(white_piece_texture[3]);
	white_king.setScale(0.65, 0.65);
	white_king.setOrigin(white_king.getGlobalBounds().getSize().x / 2 + 16, white_king.getGlobalBounds().getSize().y / 1.4);
	white_king.setPosition(square[60].getPosition());
	black_king.setTexture(black_piece_texture[3]);
	black_king.setScale(0.65, 0.65);
	black_king.setOrigin(white_king.getGlobalBounds().getSize().x / 2 + 16, white_king.getGlobalBounds().getSize().y / 1.4);
	black_king.setPosition(square[4].getPosition());
	for (int i = 0; i < 8; i++)
	{
		white_pawn[i].setTexture(white_piece_texture[5]);
		white_pawn[i].setScale(0.65, 0.65);
		white_pawn[i].setOrigin(white_king.getGlobalBounds().getSize().x / 2, white_king.getGlobalBounds().getSize().y / 1.5);
		white_pawn[i].setPosition(square[55 - i].getPosition());
		black_pawn[i].setTexture(black_piece_texture[5]);
		black_pawn[i].setScale(0.65, 0.65);
		black_pawn[i].setOrigin(black_king.getGlobalBounds().getSize().x / 2, black_king.getGlobalBounds().getSize().y / 1.5);
		black_pawn[i].setPosition(square[15 - i].getPosition());
	}
	for (int i = 0; i < 9; i++)
	{
		white_queen[i].setTexture(white_piece_texture[2]);
		white_queen[i].setScale(0.65, 0.65);
		white_queen[i].setOrigin(white_king.getGlobalBounds().getSize().x / 2 + 20, white_king.getGlobalBounds().getSize().y / 1.5);
		if (i == 0)
			white_queen[i].setPosition(square[59].getPosition());
		else
			white_queen[i].setPosition(-50, 50);
		black_queen[i].setTexture(black_piece_texture[2]);
		black_queen[i].setScale(0.65, 0.65);
		black_queen[i].setOrigin(black_king.getGlobalBounds().getSize().x / 2 + 20, black_king.getGlobalBounds().getSize().y / 1.5);
		if (i == 0)
			black_queen[i].setPosition(square[3].getPosition());
		else
			black_queen[i].setPosition(-50, 50);
	}
	for (int i = 0; i < 10; i++)
	{
		white_knight[i].setTexture(white_piece_texture[1]);
		white_knight[i].setScale(0.65, 0.65);
		white_knight[i].setOrigin(white_king.getGlobalBounds().getSize().x / 2 + 20, white_king.getGlobalBounds().getSize().y / 1.5);
		if (i < 2)
			white_knight[i].setPosition(square[57 + (i * 5)].getPosition());
		else
			white_knight[i].setPosition(-50, 50);
		black_knight[i].setTexture(black_piece_texture[1]);
		black_knight[i].setScale(0.65, 0.65);
		black_knight[i].setOrigin(black_king.getGlobalBounds().getSize().x / 2 + 20, black_king.getGlobalBounds().getSize().y / 1.5);
		if (i < 2)
			black_knight[i].setPosition(square[1 + (i * 5)].getPosition());
		else
			black_knight[i].setPosition(-50, 50);

		white_bishop[i].setTexture(white_piece_texture[0]);
		white_bishop[i].setScale(0.65, 0.65);
		white_bishop[i].setScale(0.65, 0.65);
		white_bishop[i].setOrigin(white_king.getGlobalBounds().getSize().x / 2 + 18, white_king.getGlobalBounds().getSize().y / 1.3);
		if (i < 2)
			white_bishop[i].setPosition(square[58 + (i * 3)].getPosition());
		else
			white_bishop[i].setPosition(-50, 50);
		black_bishop[i].setTexture(black_piece_texture[0]);
		black_bishop[i].setScale(0.65, 0.65);
		black_bishop[i].setScale(0.65, 0.65);
		black_bishop[i].setOrigin(white_king.getGlobalBounds().getSize().x / 2 + 18, white_king.getGlobalBounds().getSize().y / 1.3);
		if (i < 2)
			black_bishop[i].setPosition(square[2 + (i * 3)].getPosition());
		else
			black_bishop[i].setPosition(-50, 50);

		white_rook[i].setTexture(white_piece_texture[4]);
		white_rook[i].setScale(0.65, 0.65);
		white_rook[i].setOrigin(white_king.getGlobalBounds().getSize().x / 2 + 8, white_king.getGlobalBounds().getSize().y / 1.6);
		if (i < 2)
			white_rook[i].setPosition(square[56 + (i * 7)].getPosition());
		else
			white_rook[i].setPosition(-50, 50);
		black_rook[i].setTexture(black_piece_texture[4]);
		black_rook[i].setScale(0.65, 0.65);
		black_rook[i].setOrigin(white_king.getGlobalBounds().getSize().x / 2 + 8, white_king.getGlobalBounds().getSize().y / 1.6);
		if (i < 2)
			black_rook[i].setPosition(square[0 + (i * 7)].getPosition());
		else
			black_rook[i].setPosition(-50, 50);
	}
}

void Board::get_white_move_count() {
	//system("cls");
	int white_pawn_available_moves[8] = { 0 };
	int white_knight_available_moves[2] = { 0 };
	int white_bishop_available_moves[2] = { 0 };
	int white_rook_available_moves[2] = { 0 };
	int white_queen_available_moves[1] = { 0 };
	int white_king_available_moves[1] = { 0 };
	white_available_moves = 0;

	// ------------------ PAWNS ------------------
	for (int i = 0; i < 8; i++) {
		int square_index = -1;
		// find square index of pawn
		for (int s = 0; s < 64; s++) {
			if (white_pawn[i].getGlobalBounds().intersects(square[s].getGlobalBounds())) {
				square_index = s;
				break;
			}
		}
		if (square_index == -1) continue; // safety
		int row = square_index / 8;
		int col = square_index % 8;

		// forward 1
		if (row > 0 && !is_square_occupied_with_white[square_index - 8] &&
			!is_square_occupied_with_black[square_index - 8]) {
			white_pawn_available_moves[i]++;
		}

		// forward 2
		if (row == 6 &&
			!is_square_occupied_with_white[square_index - 8] &&
			!is_square_occupied_with_black[square_index - 8] &&
			!is_square_occupied_with_white[square_index - 16] &&
			!is_square_occupied_with_black[square_index - 16]) {
			white_pawn_available_moves[i]++;
		}

		// capture left
		if (row > 0 && col > 0 && is_square_occupied_with_black[square_index - 9]) {
			white_pawn_available_moves[i]++;
		}

		// capture right
		if (row > 0 && col < 7 && is_square_occupied_with_black[square_index - 7]) {
			white_pawn_available_moves[i]++;
		}

		// EN PASSANT CAPTURES
		// Check if this white pawn can perform en passant
		if (last_move_was_double_pawn && last_moved_pawn_color == "black" &&
			square_index >= 24 && square_index <= 31) { // White pawn on 5th rank

			// Check en passant capture to the left
			if (col > 0 && last_moved_pawn_square == square_index - 1) {
				// The target square would be diagonally forward-left
				int en_passant_target = square_index - 9;
				if (!is_square_occupied_with_white[en_passant_target] &&
					!is_square_occupied_with_black[en_passant_target]) {
					white_pawn_available_moves[i]++;
				}
			}

			// Check en passant capture to the right  
			if (col < 7 && last_moved_pawn_square == square_index + 1) {
				// The target square would be diagonally forward-right
				int en_passant_target = square_index - 7;
				if (!is_square_occupied_with_white[en_passant_target] &&
					!is_square_occupied_with_black[en_passant_target]) {
					white_pawn_available_moves[i]++;
				}
			}
		}
	}

	// ------------------ KNIGHTS ------------------
	int knight_offsets[8] = { -17, -15, -10, -6, 6, 10, 15, 17 };
	for (int i = 0; i < 10; i++) {
		int square_index = -1;
		for (int s = 0; s < 64; s++) {
			if (white_knight[i].getGlobalBounds().intersects(square[s].getGlobalBounds())) {
				square_index = s;
				break;
			}
		}
		if (square_index == -1) continue;

		int row = square_index / 8;
		int col = square_index % 8;

		for (int o = 0; o < 8; o++) {
			int target = square_index + knight_offsets[o];
			if (target < 0 || target >= 64) continue;

			int trow = target / 8;
			int tcol = target % 8;

			// ensure L-move stayed on board
			if (abs(trow - row) + abs(tcol - col) == 3 &&
				abs(trow - row) != 0 && abs(tcol - col) != 0) {
				if (!is_square_occupied_with_white[target]) {
					white_knight_available_moves[i]++;
				}
			}
		}
	}

	// ------------------ BISHOPS ------------------
	int bishop_directions[4] = { -9, -7, 7, 9 };
	for (int i = 0; i < 10; i++) {
		int square_index = -1;
		for (int s = 0; s < 64; s++) {
			if (white_bishop[i].getGlobalBounds().intersects(square[s].getGlobalBounds())) {
				square_index = s;
				break;
			}
		}
		if (square_index == -1) continue;

		for (int d = 0; d < 4; d++) {
			int target = square_index;
			while (true) {
				target += bishop_directions[d];
				if (target < 0 || target >= 64) break;

				int rowDiff = abs((target / 8) - (square_index / 8));
				int colDiff = abs((target % 8) - (square_index % 8));
				if (rowDiff != colDiff) break; // broke diagonal

				if (is_square_occupied_with_white[target]) break;
				white_bishop_available_moves[i]++;
				if (is_square_occupied_with_black[target]) break;
			}
		}
	}

	// ------------------ ROOKS ------------------
	int rook_directions[4] = { -8, 8, -1, 1 };
	for (int i = 0; i < 10; i++) {
		int square_index = -1;
		for (int s = 0; s < 64; s++) {
			if (white_rook[i].getGlobalBounds().intersects(square[s].getGlobalBounds())) {
				square_index = s;
				break;
			}
		}
		if (square_index == -1) continue;

		for (int d = 0; d < 4; d++) {
			int target = square_index;
			while (true) {
				target += rook_directions[d];
				if (target < 0 || target >= 64) break;

				// stay in row for left-right moves
				if ((d == 2 || d == 3) && target / 8 != square_index / 8) break;

				if (is_square_occupied_with_white[target]) break;
				white_rook_available_moves[i]++;
				if (is_square_occupied_with_black[target]) break;
			}
		}
	}

	// ------------------ QUEEN ------------------
	int queen_directions[8] = { -9, -7, 7, 9, -8, 8, -1, 1 };
	for (int i = 0; i < 9; i++) {
		int square_index = -1;
		for (int s = 0; s < 64; s++) {
			if (white_queen[i].getGlobalBounds().intersects(square[s].getGlobalBounds())) {
				square_index = s;
				break;
			}
		}
		if (square_index == -1) continue;

		for (int d = 0; d < 8; d++) {
			int target = square_index;
			while (true) {
				target += queen_directions[d];
				if (target < 0 || target >= 64) break;

				// row check for rook-like moves
				if ((d == 6 || d == 7) && target / 8 != square_index / 8) break;

				// diagonal check for bishop-like moves
				if ((d < 4) && abs((target / 8) - (square_index / 8)) != abs((target % 8) - (square_index % 8)))
					break;

				if (is_square_occupied_with_white[target]) break;
				white_queen_available_moves[i]++;
				if (is_square_occupied_with_black[target]) break;
			}
		}
	}

	// ------------------ KING ------------------
	int king_offsets[8] = { -9, -8, -7, -1, 1, 7, 8, 9 };
	for (int i = 0; i < 1; i++) {
		int square_index = -1;
		for (int s = 0; s < 64; s++) {
			if (white_king.getGlobalBounds().intersects(square[s].getGlobalBounds())) {
				square_index = s;
				break;
			}
		}
		if (square_index == -1) continue;

		for (int o = 0; o < 8; o++) {
			int target = square_index + king_offsets[o];
			if (target < 0 || target >= 64) continue;

			int row = square_index / 8;
			int col = square_index % 8;
			int trow = target / 8;
			int tcol = target % 8;

			if (abs(row - trow) <= 1 && abs(col - tcol) <= 1) {
				if (!is_square_occupied_with_white[target]) {
					white_king_available_moves[i]++;
				}
			}
		}
	}

	// ------------------ Summing moves ------------------
	for (int i = 0; i < 8; i++) white_available_moves += white_pawn_available_moves[i];
	for (int i = 0; i < 2; i++) white_available_moves += white_knight_available_moves[i];
	for (int i = 0; i < 2; i++) white_available_moves += white_bishop_available_moves[i];
	for (int i = 0; i < 2; i++) white_available_moves += white_rook_available_moves[i];
	for (int i = 0; i < 1; i++) white_available_moves += white_queen_available_moves[i];
	for (int i = 0; i < 1; i++) white_available_moves += white_king_available_moves[i];

	//cout << "Total available moves for white: " << white_available_moves << endl;
}

void Board::get_black_move_count() {
	//system("cls");
	int black_pawn_available_moves[8] = { 0 };
	int black_knight_available_moves[2] = { 0 };
	int black_bishop_available_moves[2] = { 0 };
	int black_rook_available_moves[2] = { 0 };
	int black_queen_available_moves[1] = { 0 };
	int black_king_available_moves[1] = { 0 };
	black_available_moves = 0;

	// ------------------ PAWNS ------------------
	for (int i = 0; i < 8; i++) {
		int square_index = -1;
		// find square index of pawn
		for (int s = 0; s < 64; s++) {
			if (black_pawn[i].getGlobalBounds().intersects(square[s].getGlobalBounds())) {
				square_index = s;
				break;
			}
		}
		if (square_index == -1) continue; // safety
		int row = square_index / 8;
		int col = square_index % 8;

		// forward 1
		if (row < 7 && !is_square_occupied_with_white[square_index + 8] &&
			!is_square_occupied_with_black[square_index + 8]) {
			black_pawn_available_moves[i]++;
		}

		// forward 2 (only from row 1)
		if (row == 1 &&
			!is_square_occupied_with_white[square_index + 8] &&
			!is_square_occupied_with_black[square_index + 8] &&
			!is_square_occupied_with_white[square_index + 16] &&
			!is_square_occupied_with_black[square_index + 16]) {
			black_pawn_available_moves[i]++;
		}

		// capture left (down-left = +7)
		if (row < 7 && col > 0 && is_square_occupied_with_white[square_index + 7]) {
			black_pawn_available_moves[i]++;
		}

		// capture right (down-right = +9)
		if (row < 7 && col < 7 && is_square_occupied_with_white[square_index + 9]) {
			black_pawn_available_moves[i]++;
		}

		// EN PASSANT CAPTURES
		// Check if this black pawn can perform en passant
		if (last_move_was_double_pawn && last_moved_pawn_color == "white" &&
			square_index >= 32 && square_index <= 39) { // Black pawn on 4th rank

			// Check en passant capture to the left (down-left)
			if (col > 0 && last_moved_pawn_square == square_index - 1) {
				// The target square would be diagonally forward-left
				int en_passant_target = square_index + 7;
				if (!is_square_occupied_with_white[en_passant_target] &&
					!is_square_occupied_with_black[en_passant_target]) {
					black_pawn_available_moves[i]++;
				}
			}

			// Check en passant capture to the right (down-right)
			if (col < 7 && last_moved_pawn_square == square_index + 1) {
				// The target square would be diagonally forward-right
				int en_passant_target = square_index + 9;
				if (!is_square_occupied_with_white[en_passant_target] &&
					!is_square_occupied_with_black[en_passant_target]) {
					black_pawn_available_moves[i]++;
				}
			}
		}
	}

	// ------------------ KNIGHTS ------------------
	int knight_offsets[8] = { -17, -15, -10, -6, 6, 10, 15, 17 };
	for (int i = 0; i < 10; i++) {
		int square_index = -1;
		for (int s = 0; s < 64; s++) {
			if (black_knight[i].getGlobalBounds().intersects(square[s].getGlobalBounds())) {
				square_index = s;
				break;
			}
		}
		if (square_index == -1) continue;

		int row = square_index / 8;
		int col = square_index % 8;

		for (int o = 0; o < 8; o++) {
			int target = square_index + knight_offsets[o];
			if (target < 0 || target >= 64) continue;

			int trow = target / 8;
			int tcol = target % 8;

			if (abs(trow - row) + abs(tcol - col) == 3 &&
				abs(trow - row) != 0 && abs(tcol - col) != 0) {
				if (!is_square_occupied_with_black[target]) {
					black_knight_available_moves[i]++;
				}
			}
		}
	}

	// ------------------ BISHOPS ------------------
	int bishop_directions[4] = { -9, -7, 7, 9 };
	for (int i = 0; i < 10; i++) {
		int square_index = -1;
		for (int s = 0; s < 64; s++) {
			if (black_bishop[i].getGlobalBounds().intersects(square[s].getGlobalBounds())) {
				square_index = s;
				break;
			}
		}
		if (square_index == -1) continue;

		for (int d = 0; d < 4; d++) {
			int target = square_index;
			while (true) {
				target += bishop_directions[d];
				if (target < 0 || target >= 64) break;

				int rowDiff = abs((target / 8) - (square_index / 8));
				int colDiff = abs((target % 8) - (square_index % 8));
				if (rowDiff != colDiff) break;

				if (is_square_occupied_with_black[target]) break;
				black_bishop_available_moves[i]++;
				if (is_square_occupied_with_white[target]) break;
			}
		}
	}

	// ------------------ ROOKS ------------------
	int rook_directions[4] = { -8, 8, -1, 1 };
	for (int i = 0; i < 2; i++) {
		int square_index = -1;
		for (int s = 0; s < 64; s++) {
			if (black_rook[i].getGlobalBounds().intersects(square[s].getGlobalBounds())) {
				square_index = s;
				break;
			}
		}
		if (square_index == -1) continue;

		for (int d = 0; d < 4; d++) {
			int target = square_index;
			while (true) {
				target += rook_directions[d];
				if (target < 0 || target >= 64) break;

				if ((d == 2 || d == 3) && target / 8 != square_index / 8) break;

				if (is_square_occupied_with_black[target]) break;
				black_rook_available_moves[i]++;
				if (is_square_occupied_with_white[target]) break;
			}
		}
	}

	// ------------------ QUEEN ------------------
	int queen_directions[8] = { -9, -7, 7, 9, -8, 8, -1, 1 };
	for (int i = 0; i < 9; i++) {
		int square_index = -1;
		for (int s = 0; s < 64; s++) {
			if (black_queen[i].getGlobalBounds().intersects(square[s].getGlobalBounds())) {
				square_index = s;
				break;
			}
		}
		if (square_index == -1) continue;

		for (int d = 0; d < 8; d++) {
			int target = square_index;
			while (true) {
				target += queen_directions[d];
				if (target < 0 || target >= 64) break;

				if ((d == 6 || d == 7) && target / 8 != square_index / 8) break;
				if ((d < 4) && abs((target / 8) - (square_index / 8)) != abs((target % 8) - (square_index % 8)))
					break;

				if (is_square_occupied_with_black[target]) break;
				black_queen_available_moves[i]++;
				if (is_square_occupied_with_white[target]) break;
			}
		}
	}

	// ------------------ KING ------------------
	int king_offsets[8] = { -9, -8, -7, -1, 1, 7, 8, 9 };
	for (int i = 0; i < 1; i++) {
		int square_index = -1;
		for (int s = 0; s < 64; s++) {
			if (black_king.getGlobalBounds().intersects(square[s].getGlobalBounds())) {
				square_index = s;
				break;
			}
		}
		if (square_index == -1) continue;

		for (int o = 0; o < 8; o++) {
			int target = square_index + king_offsets[o];
			if (target < 0 || target >= 64) continue;

			int row = square_index / 8;
			int col = square_index % 8;
			int trow = target / 8;
			int tcol = target % 8;

			if (abs(row - trow) <= 1 && abs(col - tcol) <= 1) {
				if (!is_square_occupied_with_black[target]) {
					black_king_available_moves[i]++;
				}
			}
		}
	}

	// ------------------ Summing moves ------------------
	for (int i = 0; i < 8; i++) black_available_moves += black_pawn_available_moves[i];
	for (int i = 0; i < 2; i++) black_available_moves += black_knight_available_moves[i];
	for (int i = 0; i < 2; i++) black_available_moves += black_bishop_available_moves[i];
	for (int i = 0; i < 2; i++) black_available_moves += black_rook_available_moves[i];
	for (int i = 0; i < 1; i++) black_available_moves += black_queen_available_moves[i];
	for (int i = 0; i < 1; i++) black_available_moves += black_king_available_moves[i];

	//cout << "\nTotal available moves for black: " << black_available_moves << endl;
}

bool Board::get_white_available_paths(string& piece_type, int& target_square_id, int piece_id)
{
	//WHITE_PAWN AVAILABLE PATHS
	if (piece_type == "white_pawn" && is_square_occupied_with_white[target_square_id] == false)
	{
		// Regular forward move
		if (get_white_pawn_square - 8 == target_square_id && !is_square_occupied_with_black[target_square_id])
		{
			is_square_occupied_with_white[target_square_id] = true;
			is_square_occupied_with_white[get_white_pawn_square] = false;
			sounds.playSounds();

			// Reset en passant tracking since this wasn't a double move
			last_move_was_double_pawn = false;
			last_moved_pawn_square = -1;
			last_moved_pawn_color = "";

			// Switch to queen
			if (target_square_id >= 0 && target_square_id <= 7) {
				white_pawn[piece_id].setPosition(9999, 9999);
				white_queen_count++;
				white_queen[white_queen_count].setPosition(square[target_square_id].getPosition());
			}
			else
				white_pawn[piece_id].setPosition(square[target_square_id].getPosition());
			return true;
		}
		// Double pawn move from starting position
		else if (get_white_pawn_square - 16 == target_square_id && get_white_pawn_square >= 48 && get_white_pawn_square <= 55
			&& !is_square_occupied_with_white[get_white_pawn_square - 8] && !is_square_occupied_with_black[get_white_pawn_square - 8])
		{
			is_square_occupied_with_white[target_square_id] = true;
			is_square_occupied_with_white[get_white_pawn_square] = false;
			sounds.playSounds();
			white_pawn[piece_id].setPosition(square[target_square_id].getPosition());

			// Track this double pawn move for en passant
			last_move_was_double_pawn = true;
			last_moved_pawn_square = target_square_id;
			last_moved_pawn_color = "white";

			return true;
		}
		// Regular diagonal capture
		else if ((get_white_pawn_square - 9 == target_square_id || get_white_pawn_square - 7 == target_square_id)
			&& is_square_occupied_with_black[target_square_id])
		{
			is_square_occupied_with_white[target_square_id] = true;
			is_square_occupied_with_black[target_square_id] = false;
			is_square_occupied_with_white[get_white_pawn_square] = false;
			sounds.playSounds();

			// Reset en passant tracking
			last_move_was_double_pawn = false;
			last_moved_pawn_square = -1;
			last_moved_pawn_color = "";

			if (target_square_id >= 0 && target_square_id <= 7) {
				white_pawn[piece_id].setPosition(9999, 9999);
				white_queen_count++;
				white_queen[white_queen_count].setPosition(square[target_square_id].getPosition());
			}
			else
				white_pawn[piece_id].setPosition(square[target_square_id].getPosition());
			return true;
		}
		// EN PASSANT CAPTURE
		else if ((get_white_pawn_square - 9 == target_square_id || get_white_pawn_square - 7 == target_square_id)
			&& !is_square_occupied_with_black[target_square_id] && !is_square_occupied_with_white[target_square_id]
			&& last_move_was_double_pawn && last_moved_pawn_color == "black"
			&& last_moved_pawn_square == target_square_id + 8
			&& get_white_pawn_square >= 24 && get_white_pawn_square <= 31) // White pawn on 5th rank
		{
			// Check if we're on the same rank as the pawn that just moved
			if (abs((get_white_pawn_square % 8) - (last_moved_pawn_square % 8)) == 1)
			{
				is_square_occupied_with_white[target_square_id] = true;
				is_square_occupied_with_white[get_white_pawn_square] = false;

				// Remove the captured black pawn (it's at target_square_id + 8)
				is_square_occupied_with_black[last_moved_pawn_square] = false;

				// Find and remove the captured black pawn visually
				for (int j = 0; j < 8; j++)
				{
					if (black_pawn[j].getGlobalBounds().intersects(square[last_moved_pawn_square].getGlobalBounds()))
					{
						black_pawn[j].setPosition(9999, 9999); // Move off screen
						break;
					}
				}

				sounds.playSounds();
				white_pawn[piece_id].setPosition(square[target_square_id].getPosition());

				// Reset en passant tracking
				last_move_was_double_pawn = false;
				last_moved_pawn_square = -1;
				last_moved_pawn_color = "";

				return true;
			}
		}
		else
		{
			is_square_occupied_with_white[target_square_id] = false;
			is_square_occupied_with_white[get_white_pawn_square] = true;
			return false;
		}
	}
	else if (piece_type == "white_knight" && is_square_occupied_with_white[target_square_id] == false)
	{
		if (get_white_knight_square - 17 == target_square_id || get_white_knight_square - 15 == target_square_id
			|| get_white_knight_square - 10 == target_square_id || get_white_knight_square - 6 == target_square_id
			|| get_white_knight_square + 6 == target_square_id || get_white_knight_square + 10 == target_square_id
			|| get_white_knight_square + 15 == target_square_id || get_white_knight_square + 17 == target_square_id)
		{
			is_square_occupied_with_white[target_square_id] = true;
			is_square_occupied_with_black[target_square_id] = false;
			is_square_occupied_with_white[get_white_knight_square] = false;
			sounds.playSounds();
			return true;
		}
		else
		{
			is_square_occupied_with_white[target_square_id] = false;
			is_square_occupied_with_white[get_white_knight_square] = true;
			return false;
		}
	}
	else if (piece_type == "white_queen" && is_square_occupied_with_white[target_square_id] == false) 
	{
		int step; // Direction multiplier for step movement
		int step_size; // Distance between squares in movement path

		// Vertical Movement (up and down)
		if ((target_square_id - get_white_queen_square) % 8 == 0) 
		{
			step = (target_square_id > get_white_queen_square) ? 1 : -1; // Determine direction (up or down)
			step_size = 8;

			// Check for blocking pieces in the vertical path
			for (int square = get_white_queen_square + step * step_size; square != target_square_id; square += step * step_size)
				if (is_square_occupied_with_white[square] || is_square_occupied_with_black[square])
					return false;
		}
		// Horizontal Movement (left and right)
		else if (get_white_queen_square / 8 == target_square_id / 8)
		{
			step = (target_square_id > get_white_queen_square) ? 1 : -1; // Determine direction (left or right)
			step_size = 1;

			// Check for blocking pieces in the horizontal path
			for (int square = get_white_queen_square + step * step_size; square != target_square_id; square += step * step_size)
				if (is_square_occupied_with_white[square] || is_square_occupied_with_black[square])
					return false;
		}
		// Diagonal Movement (right-up or left-down)
		else if ((target_square_id - get_white_queen_square) % 7 == 0)
		{
			step = (target_square_id > get_white_queen_square) ? 1 : -1; // Determine direction
			step_size = 7;
			// Check for blocking pieces in the diagonal path
			for (int square = get_white_queen_square + step * step_size; square != target_square_id; square += step * step_size) 
				if (is_square_occupied_with_white[square] || is_square_occupied_with_black[square])
					return false;
		}
		// Diagonal Movement (left-up or right-down)
		else if ((target_square_id - get_white_queen_square) % 9 == 0) 
		{
			step = (target_square_id > get_white_queen_square) ? 1 : -1; // Determine direction
			step_size = 9;
			// Check for blocking pieces in the diagonal path
			for (int square = get_white_queen_square + step * step_size; square != target_square_id; square += step * step_size)
				if (is_square_occupied_with_white[square] || is_square_occupied_with_black[square])
					return false;
		}
		else
			return false;

		is_square_occupied_with_white[target_square_id] = true;
		is_square_occupied_with_black[target_square_id] = false;
		is_square_occupied_with_white[get_white_queen_square] = false;
		sounds.playSounds();
		return true;
	}
	else if (piece_type == "white_bishop" && is_square_occupied_with_white[target_square_id] == false)
	{
		int step; // Direction multiplier for step movement
		int step_size; // Distance between squares in movement path

		if ((target_square_id - get_white_bishop_square) % 7 == 0)
		{
			step = (target_square_id > get_white_bishop_square) ? 1 : -1;
			step_size = 7;
			// Check for blocking pieces in the diagonal path
			for (int square = get_white_bishop_square + step * step_size; square != target_square_id; square += step * step_size)
				if (is_square_occupied_with_white[square] || is_square_occupied_with_black[square])
					return false;
		}
		// Diagonal Movement (left-up or right-down)
		else if ((target_square_id - get_white_bishop_square) % 9 == 0)
		{
			step = (target_square_id > get_white_bishop_square) ? 1 : -1;
			step_size = 9;
			// Check for blocking pieces in the diagonal path
			for (int square = get_white_bishop_square + step * step_size; square != target_square_id; square += step * step_size) 
				if (is_square_occupied_with_white[square] || is_square_occupied_with_black[square])
					return false;
		}
		else
			return false;

		is_square_occupied_with_white[target_square_id] = true;
		is_square_occupied_with_black[target_square_id] = false;
		is_square_occupied_with_white[get_white_bishop_square] = false;
		sounds.playSounds();
		return true;
	}
	else if (piece_type == "white_rook" && is_square_occupied_with_white[target_square_id] == false)
	{
		int step; 
		int step_size; 

		if ((target_square_id - get_white_rook_square) % 8 == 0)
		{
			step = (target_square_id > get_white_rook_square) ? 1 : -1;
			step_size = 8;

			for (int square = get_white_rook_square + step * step_size; square != target_square_id; square += step * step_size)
				if (is_square_occupied_with_white[square] || is_square_occupied_with_black[square])
					return false;
		}
		else if (get_white_rook_square / 8 == target_square_id / 8)
		{
			step = (target_square_id > get_white_rook_square) ? 1 : -1;
			step_size = 1;

			for (int square = get_white_rook_square + step * step_size; square != target_square_id; square += step * step_size)
				if (is_square_occupied_with_white[square] || is_square_occupied_with_black[square])
					return false;
		}
		else
			return false;

		is_square_occupied_with_white[target_square_id] = true;
		is_square_occupied_with_black[target_square_id] = false;
		is_square_occupied_with_white[get_white_rook_square] = false;
		if (get_white_rook_square == 63)
			has_right_white_rook_moved = true;
		if (get_white_rook_square == 56)
			has_left_white_rook_moved = true;
		sounds.playSounds();
		return true;
	}
	else if (piece_type == "white_king" && is_square_occupied_with_white[target_square_id] == false)
	{
		// Basic movement
		if (get_white_king_square - 8 == target_square_id || get_white_king_square - 9 == target_square_id
			|| get_white_king_square - 7 == target_square_id || get_white_king_square - 1 == target_square_id
			|| get_white_king_square + 1 == target_square_id || get_white_king_square + 7 == target_square_id
			|| get_white_king_square + 8 == target_square_id || get_white_king_square + 9 == target_square_id)
		{
			is_square_occupied_with_white[target_square_id] = true;
			is_square_occupied_with_black[target_square_id] = false;
			is_square_occupied_with_white[get_white_king_square] = false;
			sounds.playSounds();
			return true;
		}
		// Right castle
		else if (!is_square_occupied_with_white[target_square_id - 1] 
			&& (!has_white_king_moved && get_white_king_square + 2 == target_square_id && !has_right_white_rook_moved))
		{
			has_white_king_moved = true;
			is_square_occupied_with_white[target_square_id] = true;
			is_square_occupied_with_white[get_white_king_square] = false;

			is_square_occupied_with_white[target_square_id - 1] = true;
			is_square_occupied_with_white[target_square_id + 1] = false;
			has_right_white_rook_moved = true;
			white_rook[1].setPosition(white_rook[1].getPosition().x - (2 * 80), white_rook[1].getPosition().y);
			sounds.playSounds();
			return true;
		}
		// Left castle
		else if (!is_square_occupied_with_white[target_square_id + 1] 
			&& !is_square_occupied_with_white[target_square_id - 1] 
			&& (!has_white_king_moved && get_white_king_square - 2 == target_square_id && !has_left_white_rook_moved))
		{
			has_white_king_moved = true;
			is_square_occupied_with_white[target_square_id] = true;
			is_square_occupied_with_white[get_white_king_square] = false;

			is_square_occupied_with_white[target_square_id + 1] = true;
			is_square_occupied_with_white[target_square_id - 2] = false;
			has_right_white_rook_moved = true;
			white_rook[0].setPosition(white_rook[0].getPosition().x + (3 * 80), white_rook[0].getPosition().y);
			sounds.playSounds();
			return true;
		}
		else
		{
			is_square_occupied_with_white[target_square_id] = false;
			is_square_occupied_with_white[get_white_king_square] = true;
			return false;
		}
	}
	else
		return false;
}

bool Board::get_black_available_paths(string& piece_type, int& target_square_id, int piece_id)
{
	//BLACK_PAWN AVAILABLE PATHS
	if (piece_type == "black_pawn" && is_square_occupied_with_black[target_square_id] == false)
	{
		// Regular forward move
		if (get_black_pawn_square + 8 == target_square_id && !is_square_occupied_with_white[target_square_id])
		{
			is_square_occupied_with_black[target_square_id] = true;
			is_square_occupied_with_black[get_black_pawn_square] = false;
			sounds.playSounds();

			// Reset en passant tracking since this wasn't a double move
			last_move_was_double_pawn = false;
			last_moved_pawn_square = -1;
			last_moved_pawn_color = "";

			if (target_square_id >= 56 && target_square_id <= 63) {
				black_pawn[piece_id].setPosition(9999, 9999);
				black_queen_count++;
				black_queen[black_queen_count].setPosition(square[target_square_id].getPosition());
			}
			else
				black_pawn[piece_id].setPosition(square[target_square_id].getPosition());
			return true;
		}
		// Double pawn move from starting position
		else if (get_black_pawn_square + 16 == target_square_id && get_black_pawn_square >= 8 && get_black_pawn_square <= 15
			&& !is_square_occupied_with_white[target_square_id - 8] && !is_square_occupied_with_black[target_square_id - 8])
		{
			is_square_occupied_with_black[target_square_id] = true;
			is_square_occupied_with_black[get_black_pawn_square] = false;
			black_pawn[piece_id].setPosition(square[target_square_id].getPosition());
			sounds.playSounds();

			// Track this double pawn move for en passant
			last_move_was_double_pawn = true;
			last_moved_pawn_square = target_square_id;
			last_moved_pawn_color = "black";

			return true;
		}
		// Regular diagonal capture
		else if ((get_black_pawn_square + 9 == target_square_id || get_black_pawn_square + 7 == target_square_id)
			&& is_square_occupied_with_white[target_square_id])
		{
			is_square_occupied_with_black[target_square_id] = true;
			is_square_occupied_with_white[target_square_id] = false;
			is_square_occupied_with_black[get_black_pawn_square] = false;
			sounds.playSounds();

			// Reset en passant tracking
			last_move_was_double_pawn = false;
			last_moved_pawn_square = -1;
			last_moved_pawn_color = "";

			if (target_square_id >= 56 && target_square_id <= 63) {
				black_pawn[piece_id].setPosition(9999, 9999);
				black_queen_count++;
				black_queen[black_queen_count].setPosition(square[target_square_id].getPosition());
			}
			else
				black_pawn[piece_id].setPosition(square[target_square_id].getPosition());
			return true;
		}
		// EN PASSANT CAPTURE
		else if ((get_black_pawn_square + 9 == target_square_id || get_black_pawn_square + 7 == target_square_id)
			&& !is_square_occupied_with_white[target_square_id] && !is_square_occupied_with_black[target_square_id]
			&& last_move_was_double_pawn && last_moved_pawn_color == "white"
			&& last_moved_pawn_square == target_square_id - 8
			&& get_black_pawn_square >= 32 && get_black_pawn_square <= 39) // Black pawn on 4th rank
		{
			// Check if we're on the same rank as the pawn that just moved
			if (abs((get_black_pawn_square % 8) - (last_moved_pawn_square % 8)) == 1)
			{
				is_square_occupied_with_black[target_square_id] = true;
				is_square_occupied_with_black[get_black_pawn_square] = false;

				// Remove the captured white pawn (it's at target_square_id - 8)
				is_square_occupied_with_white[last_moved_pawn_square] = false;

				// Find and remove the captured white pawn visually
				for (int j = 0; j < 8; j++)
				{
					if (white_pawn[j].getGlobalBounds().intersects(square[last_moved_pawn_square].getGlobalBounds()))
					{
						white_pawn[j].setPosition(9999, 9999); // Move off screen
						break;
					}
				}

				sounds.playSounds();
				black_pawn[piece_id].setPosition(square[target_square_id].getPosition());

				// Reset en passant tracking
				last_move_was_double_pawn = false;
				last_moved_pawn_square = -1;
				last_moved_pawn_color = "";

				return true;
			}
		}
		else
		{
			is_square_occupied_with_black[target_square_id] = false;
			is_square_occupied_with_black[get_black_pawn_square] = true;
			return false;
		}
	}
	else if (piece_type == "black_knight" && is_square_occupied_with_black[target_square_id] == false)
	{
		if (get_black_knight_square - 17 == target_square_id || get_black_knight_square - 15 == target_square_id
			|| get_black_knight_square - 10 == target_square_id || get_black_knight_square - 6 == target_square_id
			|| get_black_knight_square + 6 == target_square_id || get_black_knight_square + 10 == target_square_id
			|| get_black_knight_square + 15 == target_square_id || get_black_knight_square + 17 == target_square_id)
		{
			is_square_occupied_with_black[target_square_id] = true;
			is_square_occupied_with_white[target_square_id] = false;
			is_square_occupied_with_black[get_black_knight_square] = false;
			sounds.playSounds();
			return true;
		}
		else
		{
			is_square_occupied_with_black[target_square_id] = false;
			is_square_occupied_with_black[get_black_knight_square] = true;
			return false;
		}
	}
	else if (piece_type == "black_queen" && is_square_occupied_with_black[target_square_id] == false)
	{
		int step; // Direction multiplier for step movement
		int step_size; // Distance between squares in movement path

		// Vertical Movement (up and down)
		if ((target_square_id - get_black_queen_square) % 8 == 0)
		{
			step = (target_square_id > get_black_queen_square) ? 1 : -1; // Determine direction (up or down)
			step_size = 8;

			// Check for blocking pieces in the vertical path
			for (int square = get_black_queen_square + step * step_size; square != target_square_id; square += step * step_size)
				if (is_square_occupied_with_white[square] || is_square_occupied_with_black[square])
					return false;
		}
		// Horizontal Movement (left and right)
		else if (get_black_queen_square / 8 == target_square_id / 8)
		{
			step = (target_square_id > get_black_queen_square) ? 1 : -1; // Determine direction (left or right)
			step_size = 1;

			// Check for blocking pieces in the horizontal path
			for (int square = get_black_queen_square + step * step_size; square != target_square_id; square += step * step_size)
				if (is_square_occupied_with_white[square] || is_square_occupied_with_black[square])
					return false;
		}
		// Diagonal Movement (right-up or left-down)
		else if ((target_square_id - get_black_queen_square) % 7 == 0)
		{
			step = (target_square_id > get_black_queen_square) ? 1 : -1; // Determine direction
			step_size = 7;
			// Check for blocking pieces in the diagonal path
			for (int square = get_black_queen_square + step * step_size; square != target_square_id; square += step * step_size)
				if (is_square_occupied_with_white[square] || is_square_occupied_with_black[square])
					return false;
		}
		// Diagonal Movement (left-up or right-down)
		else if ((target_square_id - get_black_queen_square) % 9 == 0)
		{
			step = (target_square_id > get_black_queen_square) ? 1 : -1; // Determine direction
			step_size = 9;
			// Check for blocking pieces in the diagonal path
			for (int square = get_black_queen_square + step * step_size; square != target_square_id; square += step * step_size)
				if (is_square_occupied_with_white[square] || is_square_occupied_with_black[square])
					return false;
		}
		else
			return false;

		is_square_occupied_with_black[target_square_id] = true;
		is_square_occupied_with_white[target_square_id] = false;
		is_square_occupied_with_black[get_black_queen_square] = false;
		sounds.playSounds();
		return true;
	}
	else if (piece_type == "black_bishop" && is_square_occupied_with_black[target_square_id] == false)
	{
		int step; // Direction multiplier for step movement
		int step_size; // Distance between squares in movement path

		if ((target_square_id - get_black_bishop_square) % 7 == 0)
		{
			step = (target_square_id > get_black_bishop_square) ? 1 : -1;
			step_size = 7;
			// Check for blocking pieces in the diagonal path
			for (int square = get_black_bishop_square + step * step_size; square != target_square_id; square += step * step_size)
				if (is_square_occupied_with_white[square] || is_square_occupied_with_black[square])
					return false;
		}
		// Diagonal Movement (left-up or right-down)
		else if ((target_square_id - get_black_bishop_square) % 9 == 0)
		{
			step = (target_square_id > get_black_bishop_square) ? 1 : -1;
			step_size = 9;
			// Check for blocking pieces in the diagonal path
			for (int square = get_black_bishop_square + step * step_size; square != target_square_id; square += step * step_size)
				if (is_square_occupied_with_white[square] || is_square_occupied_with_black[square])
					return false;
		}
		else
			return false;

		is_square_occupied_with_black [target_square_id] = true;
		is_square_occupied_with_white[target_square_id] = false;
		is_square_occupied_with_black[get_black_bishop_square] = false;
		sounds.playSounds();
		return true;
	}
	else if (piece_type == "black_rook" && is_square_occupied_with_black[target_square_id] == false)
	{
		int step;
		int step_size;

		if ((target_square_id - get_black_rook_square) % 8 == 0)
		{
			step = (target_square_id > get_black_rook_square) ? 1 : -1;
			step_size = 8;

			for (int square = get_black_rook_square + step * step_size; square != target_square_id; square += step * step_size)
				if (is_square_occupied_with_white[square] || is_square_occupied_with_black[square])
					return false;
		}
		else if (get_black_rook_square / 8 == target_square_id / 8)
		{
			step = (target_square_id > get_black_rook_square) ? 1 : -1;
			step_size = 1;

			for (int square = get_black_rook_square + step * step_size; square != target_square_id; square += step * step_size)
				if (is_square_occupied_with_white[square] || is_square_occupied_with_black[square])
					return false;
		}
		else
			return false;

		is_square_occupied_with_black[target_square_id] = true;
		is_square_occupied_with_white[target_square_id] = false;
		is_square_occupied_with_black[get_black_rook_square] = false;
		sounds.playSounds();
		return true;
	}
	else if (piece_type == "black_king" && is_square_occupied_with_black[target_square_id] == false)
	{
		if (get_black_king_square - 8 == target_square_id || get_black_king_square - 9 == target_square_id
			|| get_black_king_square - 7 == target_square_id || get_black_king_square - 1 == target_square_id
			|| get_black_king_square + 1 == target_square_id || get_black_king_square + 7 == target_square_id
			|| get_black_king_square + 8 == target_square_id || get_black_king_square + 9 == target_square_id)
		{
			is_square_occupied_with_black[target_square_id] = true;
			is_square_occupied_with_white[target_square_id] = false;
			is_square_occupied_with_black[get_black_king_square] = false;
			sounds.playSounds();
			return true;
		}
		// Right castle
		else if (!is_square_occupied_with_black[target_square_id - 1]
			&& (!has_black_king_moved && get_black_king_square + 2 == target_square_id && !has_right_black_rook_moved))
		{
			has_black_king_moved = true;
			is_square_occupied_with_black[target_square_id] = true;
			is_square_occupied_with_black[get_black_king_square] = false;

			is_square_occupied_with_black[target_square_id - 1] = true;
			is_square_occupied_with_black[target_square_id + 1] = false;
			has_right_black_rook_moved = true;
			black_rook[1].setPosition(black_rook[1].getPosition().x - (2 * 80), black_rook[1].getPosition().y);

			sounds.playSounds();
			return true;
		}
		// Left castle
		else if (!is_square_occupied_with_black[target_square_id + 1]
			&& !is_square_occupied_with_black[target_square_id - 1]
			&& (!has_black_king_moved && get_black_king_square - 2 == target_square_id && !has_left_black_rook_moved))
		{
			has_black_king_moved = true;
			is_square_occupied_with_black[target_square_id] = true;
			is_square_occupied_with_black[get_black_king_square] = false;

			is_square_occupied_with_black[target_square_id + 1] = true;
			is_square_occupied_with_black[target_square_id - 2] = false;
			has_right_black_rook_moved = true;
			black_rook[0].setPosition(black_rook[0].getPosition().x + (3 * 80), black_rook[0].getPosition().y);

			sounds.playSounds();
			return true;
		}
		else
		{
			is_square_occupied_with_black[target_square_id] = false;
			is_square_occupied_with_black[get_black_king_square] = true;
			return false;
		}
	}
	else
		return false;
}

void Board::move_white_piece(Get_Mouse_Cursor& get_mouse_cursor)
{
	if (white_plays == true)
	{
		static int active_white_piece = -1;
		for (int i = 0; i < 8; i++)
		{
			if (get_mouse_cursor.is_left_clicking)
			{
				//MOVE WHITE PAWNS
				if (active_white_piece == -1 && get_mouse_cursor.cursor.getGlobalBounds().intersects(white_pawn[i].getGlobalBounds()))
				{
					active_white_piece = i;
					white_active_type = "white_pawn";
					for (int s = 0; s < 64; s++)
					{
						if (white_pawn[i].getGlobalBounds().intersects(square[s].getGlobalBounds()))
						{
							get_white_pawn_square = s;
							old_white_pawn_square = s;
						}
					}
				}
				if (active_white_piece == i && white_active_type == "white_pawn")
					white_pawn[i].setPosition(get_mouse_cursor.cursor.getPosition());
			}
			else
			{
				if (active_white_piece == i && white_active_type == "white_pawn")
				{
					for (int s = 0; s < 64; s++)
					{
						if (get_mouse_cursor.cursor.getGlobalBounds().intersects(square[s].getGlobalBounds()))
						{
							if (get_white_available_paths(white_active_type, s, i) == true)
							{
								remove_piece("white");
								old_white_pawn_square = s;
							}
							else
								white_pawn[i].setPosition(square[get_white_pawn_square].getPosition());
							break;
						}
					}
					active_white_piece = -1;
					white_active_type = "";
					if (get_white_pawn_square != old_white_pawn_square) {
						white_plays = false;
						update_score = true;

						if (!(last_move_was_double_pawn && last_moved_pawn_color == "white"))
						{
							last_move_was_double_pawn = false;
							last_moved_pawn_square = -1;
							last_moved_pawn_color = "";
						}
					}
				}
			}
		}
		for (int i = 0; i < 9; i++)
		{
			if (get_mouse_cursor.is_left_clicking)
			{
				//MOVE WHITE QUEEN
				if (active_white_piece == -1 && get_mouse_cursor.cursor.getGlobalBounds().intersects(white_queen[i].getGlobalBounds()))
				{
					active_white_piece = i;
					white_active_type = "white_queen";
					for (int s = 0; s < 64; s++)
					{
						if (white_queen[i].getGlobalBounds().intersects(square[s].getGlobalBounds()))
						{
							get_white_queen_square = s;
							old_white_queen_square = s;
						}
					}
				}
				if (active_white_piece == i && white_active_type == "white_queen")
					white_queen[i].setPosition(get_mouse_cursor.cursor.getPosition());
			}
			else
			{
				if (active_white_piece == i && white_active_type == "white_queen")
				{
					for (int s = 0; s < 64; s++)
					{
						if (get_mouse_cursor.cursor.getGlobalBounds().intersects(square[s].getGlobalBounds()))
						{
							if (get_white_available_paths(white_active_type, s, i) == true)
							{
								white_queen[i].setPosition(square[s].getPosition());
								remove_piece("white");
								old_white_queen_square = s;
							}
							else
								white_queen[i].setPosition(square[get_white_queen_square].getPosition());
							break;
						}
					}
					active_white_piece = -1;
					white_active_type = "";
					if (get_white_queen_square != old_white_queen_square) {
						white_plays = false;
						update_score = true;

						if (!(last_move_was_double_pawn && last_moved_pawn_color == "white"))
						{
							last_move_was_double_pawn = false;
							last_moved_pawn_square = -1;
							last_moved_pawn_color = "";
						}
					}
				}
			}
		}
		for (int i = 0; i < 10; i++)
		{
			if (get_mouse_cursor.is_left_clicking)
			{
				//MOVE WHITE KNIGHTS
				if (active_white_piece == -1 && get_mouse_cursor.cursor.getGlobalBounds().intersects(white_knight[i].getGlobalBounds()))
				{
					active_white_piece = i;
					white_active_type = "white_knight";
					for (int s = 0; s < 64; s++)
					{
						if (white_knight[i].getGlobalBounds().intersects(square[s].getGlobalBounds()))
						{
							get_white_knight_square = s;
							old_white_knight_square = s;
						}
					}
				}
				if (active_white_piece == i && white_active_type == "white_knight")
					white_knight[i].setPosition(get_mouse_cursor.cursor.getPosition());

				//MOVE WHITE BISHOPS
				if (active_white_piece == -1 && get_mouse_cursor.cursor.getGlobalBounds().intersects(white_bishop[i].getGlobalBounds()))
				{
					active_white_piece = i;
					white_active_type = "white_bishop";
					for (int s = 0; s < 64; s++)
					{
						if (white_bishop[i].getGlobalBounds().intersects(square[s].getGlobalBounds()))
						{
							get_white_bishop_square = s;
							old_white_bishop_square = s;
						}
					}
				}
				if (active_white_piece == i && white_active_type == "white_bishop")
					white_bishop[i].setPosition(get_mouse_cursor.cursor.getPosition());

				//MOVE WHITE ROOK
				if (active_white_piece == -1 && get_mouse_cursor.cursor.getGlobalBounds().intersects(white_rook[i].getGlobalBounds()))
				{
					active_white_piece = i;
					white_active_type = "white_rook";
					for (int s = 0; s < 64; s++)
					{
						if (white_rook[i].getGlobalBounds().intersects(square[s].getGlobalBounds()))
						{
							get_white_rook_square = s;
							old_white_rook_square = s;
						}
					}
				}
				if (active_white_piece == i && white_active_type == "white_rook")
					white_rook[i].setPosition(get_mouse_cursor.cursor.getPosition());
			}
			else
			{
				if (active_white_piece == i && white_active_type == "white_knight")
				{
					for (int s = 0; s < 64; s++)
					{
						if (get_mouse_cursor.cursor.getGlobalBounds().intersects(square[s].getGlobalBounds()))
						{
							if (get_white_available_paths(white_active_type, s, i) == true)
							{
								white_knight[i].setPosition(square[s].getPosition());
								remove_piece("white");
								old_white_knight_square = s;
							}
							else
								white_knight[i].setPosition(square[get_white_knight_square].getPosition());
							break;
						}
					}
					active_white_piece = -1;
					white_active_type = "";
					if (old_white_knight_square != get_white_knight_square) {
						white_plays = false;
						update_score = true;

						if (!(last_move_was_double_pawn && last_moved_pawn_color == "white"))
						{
							last_move_was_double_pawn = false;
							last_moved_pawn_square = -1;
							last_moved_pawn_color = "";
						}
					}
				}
				if (active_white_piece == i && white_active_type == "white_bishop")
				{
					for (int s = 0; s < 64; s++)
					{
						if (get_mouse_cursor.cursor.getGlobalBounds().intersects(square[s].getGlobalBounds()))
						{
							if (get_white_available_paths(white_active_type, s, i) == true)
							{
								white_bishop[i].setPosition(square[s].getPosition());
								remove_piece("white");
								old_white_bishop_square = s;
							}
							else
								white_bishop[i].setPosition(square[get_white_bishop_square].getPosition());
							break;
						}
					}
					active_white_piece = -1;
					white_active_type = "";
					if (old_white_bishop_square != get_white_bishop_square) {
						white_plays = false;
						update_score = true;

						if (!(last_move_was_double_pawn && last_moved_pawn_color == "white"))
						{
							last_move_was_double_pawn = false;
							last_moved_pawn_square = -1;
							last_moved_pawn_color = "";
						}
					}
				}
				if (active_white_piece == i && white_active_type == "white_rook")
				{
					for (int s = 0; s < 64; s++)
					{
						if (get_mouse_cursor.cursor.getGlobalBounds().intersects(square[s].getGlobalBounds()))
						{
							if (get_white_available_paths(white_active_type, s, i) == true)
							{
								white_rook[i].setPosition(square[s].getPosition());
								remove_piece("white");
								old_white_rook_square = s;
							}
							else
								white_rook[i].setPosition(square[get_white_rook_square].getPosition());
							break;
						}
					}
					active_white_piece = -1;
					white_active_type = "";
					if (old_white_rook_square != get_white_rook_square) {
						white_plays = false;
						update_score = true;

						if (!(last_move_was_double_pawn && last_moved_pawn_color == "white"))
						{
							last_move_was_double_pawn = false;
							last_moved_pawn_square = -1;
							last_moved_pawn_color = "";
						}
					}
				}
			}
		}
		if (get_mouse_cursor.is_left_clicking)
		{
			//MOVE WHITE KING
			if (active_white_piece == -1 && get_mouse_cursor.cursor.getGlobalBounds().intersects(white_king.getGlobalBounds()))
			{
				active_white_piece = -2;
				white_active_type = "white_king";
				for (int s = 0; s < 64; s++)
				{
					if (get_mouse_cursor.cursor.getGlobalBounds().intersects(square[s].getGlobalBounds()))
					{
						get_white_king_square = s;
						old_white_king_square = s;
					}
				}
			}
			if (active_white_piece == -2 && white_active_type == "white_king")
				white_king.setPosition(get_mouse_cursor.cursor.getPosition());
		}
		else
		{
			if (active_white_piece == -2 && white_active_type == "white_king")
			{
				for (int s = 0; s < 64; s++)
				{
					if (get_mouse_cursor.cursor.getGlobalBounds().intersects(square[s].getGlobalBounds()))
					{
						if (get_white_available_paths(white_active_type, s, 0) == true)
						{
							white_king.setPosition(square[s].getPosition());
							remove_piece("white");
							old_white_king_square = s;
						}
						else
							white_king.setPosition(square[get_white_king_square].getPosition());
						break;
					}
				}
				active_white_piece = -1;
				white_active_type = "";
				if (old_white_king_square != get_white_king_square) {
					white_plays = false;
					update_score = true;

					if (!(last_move_was_double_pawn && last_moved_pawn_color == "white"))
					{
						last_move_was_double_pawn = false;
						last_moved_pawn_square = -1;
						last_moved_pawn_color = "";
					}
				}
			}
		}
	}
}

void Board::move_black_piece(Get_Mouse_Cursor& get_mouse_cursor)
{
	if (white_plays == false)
	{
		static int active_black_piece = -1;
		for (int i = 0; i < 8; i++)
		{
			if (get_mouse_cursor.is_left_clicking)
			{
				//MOVE BLACK PAWNS
				if (active_black_piece == -1 && get_mouse_cursor.cursor.getGlobalBounds().intersects(black_pawn[i].getGlobalBounds()))
				{
					active_black_piece = i;
					black_active_type = "black_pawn";
					for (int s = 0; s < 64; s++)
					{
						if (black_pawn[i].getGlobalBounds().intersects(square[s].getGlobalBounds()))
						{
							get_black_pawn_square = s;
							old_black_pawn_square = s;
						}
					}
				}
				if (active_black_piece == i && black_active_type == "black_pawn")
					black_pawn[i].setPosition(get_mouse_cursor.cursor.getPosition());
			}
			else
			{
				if (active_black_piece == i && black_active_type == "black_pawn")
				{
					for (int s = 0; s < 64; s++)
					{
						if (get_mouse_cursor.cursor.getGlobalBounds().intersects(square[s].getGlobalBounds()))
						{
							if (get_black_available_paths(black_active_type, s, i) == true)
							{
								remove_piece("black");
								old_black_pawn_square = s;
							}
							else
								black_pawn[i].setPosition(square[get_black_pawn_square].getPosition());
							break;
						}
					}
					active_black_piece = -1;
					black_active_type = "";
					if (old_black_pawn_square != get_black_pawn_square) {
						white_plays = true;
						update_score = true;

						if (!(last_move_was_double_pawn && last_moved_pawn_color == "black"))
						{
							last_move_was_double_pawn = false;
							last_moved_pawn_square = -1;
							last_moved_pawn_color = "";
						}
					}
				}
			}
		}
		for (int i = 0; i < 9; i++)
		{
			if (get_mouse_cursor.is_left_clicking)
			{
				//MOVE BLACK QUEEN
				if (active_black_piece == -1 && get_mouse_cursor.cursor.getGlobalBounds().intersects(black_queen[i].getGlobalBounds()))
				{
					active_black_piece = i;
					black_active_type = "black_queen";
					for (int s = 0; s < 64; s++)
					{
						if (black_queen[i].getGlobalBounds().intersects(square[s].getGlobalBounds()))
						{
							get_black_queen_square = s;
							old_black_queen_square = s;
						}
					}
				}
				if (active_black_piece == i && black_active_type == "black_queen")
					black_queen[i].setPosition(get_mouse_cursor.cursor.getPosition());
			}
			else
			{
				if (active_black_piece == i && black_active_type == "black_queen")
				{
					for (int s = 0; s < 64; s++)
					{
						if (get_mouse_cursor.cursor.getGlobalBounds().intersects(square[s].getGlobalBounds()))
						{
							if (get_black_available_paths(black_active_type, s, i) == true)
							{
								black_queen[i].setPosition(square[s].getPosition());
								remove_piece("black");
								old_black_queen_square = s;
							}
							else
								black_queen[i].setPosition(square[get_black_queen_square].getPosition());
							break;
						}
					}
					active_black_piece = -1;
					black_active_type = "";
					if (old_black_queen_square != get_black_queen_square) {
						white_plays = true;
						update_score = true;

						if (!(last_move_was_double_pawn && last_moved_pawn_color == "black"))
						{
							last_move_was_double_pawn = false;
							last_moved_pawn_square = -1;
							last_moved_pawn_color = "";
						}
					}
				}
			}
		}
		for (int i = 0; i < 10; i++)
		{
			if (get_mouse_cursor.is_left_clicking)
			{
				//MOVE BLACK KNIGHTS
				if (active_black_piece == -1 && get_mouse_cursor.cursor.getGlobalBounds().intersects(black_knight[i].getGlobalBounds()))
				{
					active_black_piece = i;
					black_active_type = "black_knight";
					for (int s = 0; s < 64; s++)
					{
						if (black_knight[i].getGlobalBounds().intersects(square[s].getGlobalBounds()))
						{
							get_black_knight_square = s;
							old_black_knight_square = s;
						}
					}
				}
				if (active_black_piece == i && black_active_type == "black_knight")
					black_knight[i].setPosition(get_mouse_cursor.cursor.getPosition());

				//MOVE BLACK BISHOPS
				if (active_black_piece == -1 && get_mouse_cursor.cursor.getGlobalBounds().intersects(black_bishop[i].getGlobalBounds()))
				{
					active_black_piece = i;
					black_active_type = "black_bishop";
					for (int s = 0; s < 64; s++)
					{
						if (black_bishop[i].getGlobalBounds().intersects(square[s].getGlobalBounds()))
						{
							get_black_bishop_square = s;
							old_black_bishop_square = s;
						}
					}
				}
				if (active_black_piece == i && black_active_type == "black_bishop")
					black_bishop[i].setPosition(get_mouse_cursor.cursor.getPosition());

				//MOVE BLACK ROOK
				if (active_black_piece == -1 && get_mouse_cursor.cursor.getGlobalBounds().intersects(black_rook[i].getGlobalBounds()))
				{
					active_black_piece = i;
					black_active_type = "black_rook";
					for (int s = 0; s < 64; s++)
					{
						if (black_rook[i].getGlobalBounds().intersects(square[s].getGlobalBounds()))
						{
							get_black_rook_square = s;
							old_black_rook_square = s;
						}
					}
				}
				if (active_black_piece == i && black_active_type == "black_rook")
					black_rook[i].setPosition(get_mouse_cursor.cursor.getPosition());
			}
			else
			{
				if (active_black_piece == i && black_active_type == "black_knight")
				{
					for (int s = 0; s < 64; s++)
					{
						if (get_mouse_cursor.cursor.getGlobalBounds().intersects(square[s].getGlobalBounds()))
						{
							if (get_black_available_paths(black_active_type, s, i) == true)
							{
								black_knight[i].setPosition(square[s].getPosition());
								remove_piece("black");
								old_black_knight_square = s;
							}
							else
								black_knight[i].setPosition(square[get_black_knight_square].getPosition());
							break;
						}
					}
					active_black_piece = -1;
					black_active_type = "";
					if (old_black_knight_square != get_black_knight_square) {
						white_plays = true;
						update_score = true;

						if (!(last_move_was_double_pawn && last_moved_pawn_color == "black"))
						{
							last_move_was_double_pawn = false;
							last_moved_pawn_square = -1;
							last_moved_pawn_color = "";
						}
					}
				}
				if (active_black_piece == i && black_active_type == "black_bishop")
				{
					for (int s = 0; s < 64; s++)
					{
						if (get_mouse_cursor.cursor.getGlobalBounds().intersects(square[s].getGlobalBounds()))
						{
							if (get_black_available_paths(black_active_type, s, i) == true)
							{
								black_bishop[i].setPosition(square[s].getPosition());
								remove_piece("black");
								old_black_bishop_square = s;
							}
							else
								black_bishop[i].setPosition(square[get_black_bishop_square].getPosition());
							break;
						}
					}
					active_black_piece = -1;
					black_active_type = "";
					if (old_black_bishop_square != get_black_bishop_square) {
						white_plays = true;
						update_score = true;

						if (!(last_move_was_double_pawn && last_moved_pawn_color == "black"))
						{
							last_move_was_double_pawn = false;
							last_moved_pawn_square = -1;
							last_moved_pawn_color = "";
						}
					}
				}
				if (active_black_piece == i && black_active_type == "black_rook")
				{
					for (int s = 0; s < 64; s++)
					{
						if (get_mouse_cursor.cursor.getGlobalBounds().intersects(square[s].getGlobalBounds()))
						{
							if (get_black_available_paths(black_active_type, s, i) == true)
							{
								black_rook[i].setPosition(square[s].getPosition());
								remove_piece("black");
								old_black_rook_square = s;
							}
							else
								black_rook[i].setPosition(square[get_black_rook_square].getPosition());
							break;
						}
					}
					active_black_piece = -1;
					black_active_type = "";
					if (old_black_rook_square != get_black_rook_square) {
						white_plays = true;
						update_score = true;

						if (!(last_move_was_double_pawn && last_moved_pawn_color == "black"))
						{
							last_move_was_double_pawn = false;
							last_moved_pawn_square = -1;
							last_moved_pawn_color = "";
						}
					}
				}
			}
		}
		if (get_mouse_cursor.is_left_clicking)
		{
			//MOVE BLACK KING
			if (active_black_piece == -1 && get_mouse_cursor.cursor.getGlobalBounds().intersects(black_king.getGlobalBounds()))
			{
				active_black_piece = -2;
				black_active_type = "black_king";
				for (int s = 0; s < 64; s++)
				{
					if (get_mouse_cursor.cursor.getGlobalBounds().intersects(square[s].getGlobalBounds()))
					{
						get_black_king_square = s;
						old_black_king_square = s;
					}
				}
			}
			if (active_black_piece == -2 && black_active_type == "black_king")
				black_king.setPosition(get_mouse_cursor.cursor.getPosition());
		}
		else
		{
			if (active_black_piece == -2 && black_active_type == "black_king")
			{
				for (int s = 0; s < 64; s++)
				{
					if (get_mouse_cursor.cursor.getGlobalBounds().intersects(square[s].getGlobalBounds()))
					{
						if (get_black_available_paths(black_active_type, s, 0) == true)
						{
							black_king.setPosition(square[s].getPosition());
							remove_piece("black");
							old_black_king_square = s;
						}
						else
							black_king.setPosition(square[get_black_king_square].getPosition());
						break;
					}
				}
				active_black_piece = -1;
				black_active_type = "";
				if (old_black_king_square != get_black_king_square) {
					white_plays = true;
					update_score = true;

					if (!(last_move_was_double_pawn && last_moved_pawn_color == "black"))
					{
						last_move_was_double_pawn = false;
						last_moved_pawn_square = -1;
						last_moved_pawn_color = "";
					}
				}
			}
		}
	}
}

void Board::remove_piece(string attack_team)
{
	//REMOVE BLACK PIECES
	if (attack_team == "white") {
		for (int id = 0; id < 8; id++) {
			for (int i = 0; i < 10; i++)
			{
				if (i < 8)
					if (white_pawn[id].getGlobalBounds().intersects(black_pawn[i].getGlobalBounds()))
						black_pawn[i].setPosition(99999, 9999);
				if (white_pawn[id].getGlobalBounds().intersects(black_bishop[i].getGlobalBounds()))
					black_bishop[i].setPosition(99999, 9999);
				if (white_pawn[id].getGlobalBounds().intersects(black_rook[i].getGlobalBounds()))
					black_rook[i].setPosition(99999, 9999);
				if (i < 9)
					if (white_pawn[id].getGlobalBounds().intersects(black_queen[i].getGlobalBounds()))
						black_queen[i].setPosition(99999, 9999);
				if (white_pawn[id].getGlobalBounds().intersects(black_knight[i].getGlobalBounds()))
					black_knight[i].setPosition(99999, 9999);
			}
			if (white_pawn[id].getGlobalBounds().intersects(black_king.getGlobalBounds()))
				black_king.setPosition(99999, 9999);
		}

		for (int id = 0; id < 9; id++) {
			for (int i = 0; i < 10; i++)
			{
				if (i < 8)
					if (white_queen[id].getGlobalBounds().intersects(black_pawn[i].getGlobalBounds()))
						black_pawn[i].setPosition(99999, 9999);
				if (white_queen[id].getGlobalBounds().intersects(black_bishop[i].getGlobalBounds()))
					black_bishop[i].setPosition(99999, 9999);
				if (white_queen[id].getGlobalBounds().intersects(black_rook[i].getGlobalBounds()))
					black_rook[i].setPosition(99999, 9999);
				if (i < 9)
					if (white_queen[id].getGlobalBounds().intersects(black_queen[i].getGlobalBounds()))
						black_queen[i].setPosition(99999, 9999);
				if (white_queen[id].getGlobalBounds().intersects(black_knight[i].getGlobalBounds()))
					black_knight[i].setPosition(99999, 9999);
			}
			if (white_queen[id].getGlobalBounds().intersects(black_king.getGlobalBounds()))
				black_king.setPosition(99999, 9999);
		}

		for (int id = 0; id < 10; id++) {
			for (int i = 0; i < 10; i++)
			{
				if (i < 8)
					if (white_knight[id].getGlobalBounds().intersects(black_pawn[i].getGlobalBounds()))
						black_pawn[i].setPosition(99999, 9999);
				if (white_knight[id].getGlobalBounds().intersects(black_bishop[i].getGlobalBounds()))
					black_bishop[i].setPosition(99999, 9999);
				if (white_knight[id].getGlobalBounds().intersects(black_rook[i].getGlobalBounds()))
					black_rook[i].setPosition(99999, 9999);
				if (i < 9)
					if (white_knight[id].getGlobalBounds().intersects(black_queen[i].getGlobalBounds()))
						black_queen[i].setPosition(99999, 9999);
				if (white_knight[id].getGlobalBounds().intersects(black_knight[i].getGlobalBounds()))
					black_knight[i].setPosition(99999, 9999);
			}
			if (white_knight[id].getGlobalBounds().intersects(black_king.getGlobalBounds()))
				black_king.setPosition(99999, 9999);
		}

		for (int id = 0; id < 10; id++) {
			for (int i = 0; i < 10; i++)
			{
				if (i < 8)
					if (white_rook[id].getGlobalBounds().intersects(black_pawn[i].getGlobalBounds()))
						black_pawn[i].setPosition(99999, 9999);
				if (white_rook[id].getGlobalBounds().intersects(black_bishop[i].getGlobalBounds()))
					black_bishop[i].setPosition(99999, 9999);
				if (white_rook[id].getGlobalBounds().intersects(black_rook[i].getGlobalBounds()))
					black_rook[i].setPosition(99999, 9999);
				if (i < 9)
					if (white_rook[id].getGlobalBounds().intersects(black_queen[i].getGlobalBounds()))
						black_queen[i].setPosition(99999, 9999);
				if (white_rook[id].getGlobalBounds().intersects(black_knight[i].getGlobalBounds()))
					black_knight[i].setPosition(99999, 9999);
			}
			if (white_rook[id].getGlobalBounds().intersects(black_king.getGlobalBounds()))
				black_king.setPosition(99999, 9999);
		}

		for (int id = 0; id < 10; id++) {
			for (int i = 0; i < 10; i++)
			{
				if (i < 8)
					if (white_bishop[id].getGlobalBounds().intersects(black_pawn[i].getGlobalBounds()))
						black_pawn[i].setPosition(99999, 9999);
				if (white_bishop[id].getGlobalBounds().intersects(black_bishop[i].getGlobalBounds()))
					black_bishop[i].setPosition(99999, 9999);
				if (white_bishop[id].getGlobalBounds().intersects(black_rook[i].getGlobalBounds()))
					black_rook[i].setPosition(99999, 9999);
				if (i < 9)
					if (white_bishop[id].getGlobalBounds().intersects(black_queen[i].getGlobalBounds()))
						black_queen[i].setPosition(99999, 9999);
				if (white_bishop[id].getGlobalBounds().intersects(black_knight[i].getGlobalBounds()))
					black_knight[i].setPosition(99999, 9999);
			}
			if (white_bishop[id].getGlobalBounds().intersects(black_king.getGlobalBounds()))
				black_king.setPosition(99999, 9999);
		}

		for (int i = 0; i < 10; i++)
		{
			if (i < 8)
				if (white_king.getGlobalBounds().intersects(black_pawn[i].getGlobalBounds()))
					black_pawn[i].setPosition(99999, 9999);
			if (white_king.getGlobalBounds().intersects(black_bishop[i].getGlobalBounds()))
				black_bishop[i].setPosition(99999, 9999);
			if (white_king.getGlobalBounds().intersects(black_rook[i].getGlobalBounds()))
				black_rook[i].setPosition(99999, 9999);
			if (i < 9)
				if (white_king.getGlobalBounds().intersects(black_queen[i].getGlobalBounds()))
					black_queen[i].setPosition(99999, 9999);
			if (white_king.getGlobalBounds().intersects(black_knight[i].getGlobalBounds()))
				black_knight[i].setPosition(99999, 9999);
		}
		if (white_king.getGlobalBounds().intersects(black_king.getGlobalBounds()))
			black_king.setPosition(99999, 9999);
	}
	
	if (attack_team == "black") {
		//REMOVE WHITE PIECES
		for (int id = 0; id < 8; id++) {
			for (int i = 0; i < 10; i++)
			{
				if (i < 8)
					if (black_pawn[id].getGlobalBounds().intersects(white_pawn[i].getGlobalBounds()))
						white_pawn[i].setPosition(99999, 9999);
				if (black_pawn[id].getGlobalBounds().intersects(white_bishop[i].getGlobalBounds()))
					white_bishop[i].setPosition(99999, 9999);
				if (black_pawn[id].getGlobalBounds().intersects(white_rook[i].getGlobalBounds()))
					white_rook[i].setPosition(99999, 9999);
				if (i < 9)
					if (black_pawn[id].getGlobalBounds().intersects(white_queen[i].getGlobalBounds()))
						white_queen[i].setPosition(99999, 9999);
				if (black_pawn[id].getGlobalBounds().intersects(white_knight[i].getGlobalBounds()))
					white_knight[i].setPosition(99999, 9999);
			}
			if (black_pawn[id].getGlobalBounds().intersects(white_king.getGlobalBounds()))
				white_king.setPosition(99999, 9999);
		}

		for (int id = 0; id < 9; id++) {
			for (int i = 0; i < 10; i++)
			{
				if (i < 8)
					if (black_queen[id].getGlobalBounds().intersects(white_pawn[i].getGlobalBounds()))
						white_pawn[i].setPosition(99999, 9999);
				if (black_queen[id].getGlobalBounds().intersects(white_bishop[i].getGlobalBounds()))
					white_bishop[i].setPosition(99999, 9999);
				if (black_queen[id].getGlobalBounds().intersects(white_rook[i].getGlobalBounds()))
					white_rook[i].setPosition(99999, 9999);
				if (i < 9)
					if (black_queen[id].getGlobalBounds().intersects(white_queen[i].getGlobalBounds()))
						white_queen[i].setPosition(99999, 9999);
				if (black_queen[id].getGlobalBounds().intersects(white_knight[i].getGlobalBounds()))
					white_knight[i].setPosition(99999, 9999);
			}
			if (black_queen[id].getGlobalBounds().intersects(white_king.getGlobalBounds()))
				white_king.setPosition(99999, 9999);
		}

		for (int id = 0; id < 10; id++) {
			for (int i = 0; i < 10; i++)
			{
				if (i < 8)
					if (black_knight[id].getGlobalBounds().intersects(white_pawn[i].getGlobalBounds()))
						white_pawn[i].setPosition(99999, 9999);
				if (black_knight[id].getGlobalBounds().intersects(white_bishop[i].getGlobalBounds()))
					white_bishop[i].setPosition(99999, 9999);
				if (black_knight[id].getGlobalBounds().intersects(white_rook[i].getGlobalBounds()))
					white_rook[i].setPosition(99999, 9999);
				if (i < 9)
					if (black_knight[id].getGlobalBounds().intersects(white_queen[i].getGlobalBounds()))
						white_queen[i].setPosition(99999, 9999);
				if (black_knight[id].getGlobalBounds().intersects(white_knight[i].getGlobalBounds()))
					white_knight[i].setPosition(99999, 9999);
			}
			if (black_knight[id].getGlobalBounds().intersects(white_king.getGlobalBounds()))
				white_king.setPosition(99999, 9999);
		}

		for (int id = 0; id < 10; id++) {
			for (int i = 0; i < 10; i++)
			{
				if (i < 8)
					if (black_rook[id].getGlobalBounds().intersects(white_pawn[i].getGlobalBounds()))
						white_pawn[i].setPosition(99999, 9999);
				if (black_rook[id].getGlobalBounds().intersects(white_bishop[i].getGlobalBounds()))
					white_bishop[i].setPosition(99999, 9999);
				if (black_rook[id].getGlobalBounds().intersects(white_rook[i].getGlobalBounds()))
					white_rook[i].setPosition(99999, 9999);
				if (i < 9)
					if (black_rook[id].getGlobalBounds().intersects(white_queen[i].getGlobalBounds()))
						white_queen[i].setPosition(99999, 9999);
				if (black_rook[id].getGlobalBounds().intersects(white_knight[i].getGlobalBounds()))
					white_knight[i].setPosition(99999, 9999);
			}
			if (black_rook[id].getGlobalBounds().intersects(white_king.getGlobalBounds()))
				white_king.setPosition(99999, 9999);
		}

		for (int id = 0; id < 10; id++) {
			for (int i = 0; i < 10; i++)
			{
				if (i < 8)
					if (black_bishop[id].getGlobalBounds().intersects(white_pawn[i].getGlobalBounds()))
						white_pawn[i].setPosition(99999, 9999);
				if (black_bishop[id].getGlobalBounds().intersects(white_bishop[i].getGlobalBounds()))
					white_bishop[i].setPosition(99999, 9999);
				if (black_bishop[id].getGlobalBounds().intersects(white_rook[i].getGlobalBounds()))
					white_rook[i].setPosition(99999, 9999);
				if (i < 9)
					if (black_bishop[id].getGlobalBounds().intersects(white_queen[i].getGlobalBounds()))
						white_queen[i].setPosition(99999, 9999);
				if (black_bishop[id].getGlobalBounds().intersects(white_knight[i].getGlobalBounds()))
					white_knight[i].setPosition(99999, 9999);
			}
			if (black_bishop[id].getGlobalBounds().intersects(white_king.getGlobalBounds()))
				white_king.setPosition(99999, 9999);
		}

		for (int i = 0; i < 10; i++)
		{
			if (i < 8)
				if (black_king.getGlobalBounds().intersects(white_pawn[i].getGlobalBounds()))
					white_pawn[i].setPosition(99999, 9999);
			if (black_king.getGlobalBounds().intersects(white_bishop[i].getGlobalBounds()))
				white_bishop[i].setPosition(99999, 9999);
			if (black_king.getGlobalBounds().intersects(white_rook[i].getGlobalBounds()))
				white_rook[i].setPosition(99999, 9999);
			if (i < 9)
				if (black_king.getGlobalBounds().intersects(white_queen[i].getGlobalBounds()))
					white_queen[i].setPosition(99999, 9999);
			if (black_king.getGlobalBounds().intersects(white_knight[i].getGlobalBounds()))
				white_knight[i].setPosition(99999, 9999);
		}
		if (black_king.getGlobalBounds().intersects(white_king.getGlobalBounds()))
			white_king.setPosition(99999, 9999);
	}
}

void Board::draw(RenderWindow& window)
{
	for (int i = 0; i < 64; i++)
	{
		window.draw(square[i]);
		//window.draw(square_number[i]);
	}
	window.draw(white_king);
	window.draw(black_king);
	for (int i = 0; i < 10; i++)
	{
		window.draw(white_knight[i]);
		window.draw(white_bishop[i]);
		window.draw(white_rook[i]);
		window.draw(black_knight[i]);
		window.draw(black_bishop[i]);
		window.draw(black_rook[i]);
	}
	for (int i = 0; i < 9; i++)
	{
		window.draw(white_queen[i]);
		window.draw(black_queen[i]);
	}
	for (int i = 0; i < 8; i++)
	{
		window.draw(white_pawn[i]);
		window.draw(black_pawn[i]);
	}
}