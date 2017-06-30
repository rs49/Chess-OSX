#pragma once

#include "board.h"

class Game
{
	private:
		Board mBoard;
		int mSelectedTile;
		int mSelectedPiece;

		GameState mGameState = PLAYING;

	public:
		void newBoard();
		void drawBoard();
};
