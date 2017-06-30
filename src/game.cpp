#include "game.h"

void Game::newBoard()
{
	mBoard.addPiece(21, WHITE, ROOK, true);
	mBoard.addPiece(22, WHITE, KNIGHT, true);
	mBoard.addPiece(23, WHITE, BISHOP, true);
	mBoard.addPiece(24, WHITE, QUEEN, true);
	mBoard.addPiece(25, WHITE, KING, true);
	mBoard.addPiece(26, WHITE, BISHOP, true);
	mBoard.addPiece(27, WHITE, KNIGHT, true);
	mBoard.addPiece(28, WHITE, ROOK, true);

	for (int i = 31; i< (31+8); i++)
	{
		mBoard.addPiece(i, WHITE, PAWN, true);
	}


	mBoard.addPiece(91, BLACK, ROOK, true);
	mBoard.addPiece(92, BLACK, KNIGHT, true);
	mBoard.addPiece(93, BLACK, BISHOP, true);
	mBoard.addPiece(94, BLACK, QUEEN, true);
	mBoard.addPiece(95, BLACK, KING, true);
	mBoard.addPiece(96, BLACK, BISHOP, true);
	mBoard.addPiece(97, BLACK, KNIGHT, true);
	mBoard.addPiece(98, BLACK, ROOK, true);

	for (int i = 81; i< (81+8); i++)
	{
		mBoard.addPiece(i, BLACK, PAWN, true);
	}

	mBoard.setCurrPlayer(WHITE);
	mSelectedTile = 120;
	mSelectedPiece = 0;
}

void Game::drawBoard()
{
}
