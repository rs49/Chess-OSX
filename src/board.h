#pragma once

#include "global_defs.h"
#include "piece.h"

#include <list>

using namespace std;

class Board
{
	private:
		list<Piece*> mWhitePieces;
		list<Piece*> mBlackPieces;
		Colour mCurrPlayer;
		bool mCurrPlayerInCheck = false;
		bool mCurrPlayerInCheckmate = false;

	public:
		list<Piece*> getWhitePieces();
		list<Piece*> getBlackPieces();
		void addPiece(int position120, Colour colour, PieceType pieceType, bool firstMove);
		void removePiece(int position120);
		void movePiece();
		Colour getCurrPlayer();
		void setCurrPlayer(Colour colour);
		bool isCurrPlayerInCheck();
		bool isCurrPlayerInCheckmate();
};


