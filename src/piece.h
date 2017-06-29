#pragma once

#include "global_defs.h"
#include <list>

using namespace std;

class Piece
{
	private:
		int mPosition120;
		Colour mColour;
		PieceType mPieceType;
		bool mFirstMove;

	public:
		Piece(int position120, Colour colour, PieceType pieceType, bool firstMove);
		int getPosition();
		void setPosition(int position120);
		Colour getColour();
		//void setColour(Colour colour);			// Might not be needed
		PieceType getPieceType();
		//void setPieceType(PieceType pieceType);		// Might not be needed
		bool isFirstMove();
		void setFirstMoveFalse();
		//void setFirstMove(bool firstMove);			// Might not be needed
		virtual list<uint32_t> getPotentialMoves();
		//list<uint32_t> getLegalMoves();
};
