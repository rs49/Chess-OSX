#pragma once

#include "board.h"
#include <SDL2_image/SDL_image.h>
#include <string>

class Game
{
	private:
		Board mBoard;
		int mSelectedTile;
		int mSelectedPiece;

		GameState mGameState = PLAYING;

		SDL_Texture *mWhitePawnTexture;
		SDL_Texture *mWhiteKnightTexture;
		SDL_Texture *mWhiteBishopTexture;
		SDL_Texture *mWhiteRookTexture;
		SDL_Texture *mWhiteQueenTexture;
		SDL_Texture *mWhiteKingTexture;

		SDL_Texture *mBlackPawnTexture;
		SDL_Texture *mBlackKnightTexture;
		SDL_Texture *mBlackBishopTexture;
		SDL_Texture *mBlackRookTexture;
		SDL_Texture *mBlackQueenTexture;
		SDL_Texture *mBlackKingTexture;

	public:
		void newBoard();
		void drawBoard();
		void drawPiece(Colour colour, PieceType pieceType, int position120);
		void initAssets();
		void loadTexture(SDL_Texture **targetTexture, string pathName);
};
