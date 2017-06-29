#pragma once

enum Colour { WHITE, BLACK };
enum PieceType { PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING };

enum GameState { MAINMENU, PLAYING, OPTIONS };

extern int board120to64[120];

void initBoard120to64();
bool isValidTile(int position120);

