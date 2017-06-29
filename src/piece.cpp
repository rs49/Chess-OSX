#include "piece.h"

Piece::Piece(int position120, Colour colour, PieceType pieceType, bool firstMove)
{
	mPosition120 = position120;
	mColour = colour;
	mPieceType = pieceType;
	mFirstMove = firstMove;
}

int Piece::getPosition()
{
	return mPosition120;
}

void Piece::setPosition(int position120)
{
	mPosition120 = position120;
}

Colour Piece::getColour()
{
	return mColour;
}

// Might not be needed

/*Colour Piece::setColour(Colour colour)
{
	mColour = colour;
}*/

PieceType Piece::getPieceType()
{
	return mPieceType;
}

bool Piece::isFirstMove()
{
	return mFirstMove;
}

void Piece::setFirstMoveFalse()
{
	mFirstMove = false;
}

list<uint32_t> Piece::getPotentialMoves()
{
	list<uint32_t> moves;
	return moves;
}
	
