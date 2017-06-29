#include "board.h"

#include "pawn.h"
#include "knight.h"
#include "bishop.h"
#include "rook.h"
#include "queen.h"
#include "king.h"

list<Piece*> Board::getWhitePieces()
{
	return mWhitePieces;
}

list<Piece*> Board::getBlackPieces()
{
	return mBlackPieces;
}

void Board::addPiece(int position120, Colour colour, PieceType pieceType, bool firstMove)
{
	switch(pieceType)
	{
		case PAWN:
			{
				
				(colour == WHITE) 
				? mWhitePieces.push_back(new Pawn(position120, WHITE, firstMove)) :
				  mBlackPieces.push_back(new Pawn(position120, BLACK, firstMove));
				
				break;
			}
		case KNIGHT:
			{
				
				(colour == WHITE) 
				? mWhitePieces.push_back(new Knight(position120, WHITE, firstMove)) :
				  mBlackPieces.push_back(new Knight(position120, BLACK, firstMove));
				
				break;
			}
		case BISHOP:
			{
				
				(colour == WHITE) 
				? mWhitePieces.push_back(new Bishop(position120, WHITE, firstMove)) :
				  mBlackPieces.push_back(new Bishop(position120, BLACK, firstMove));
				
				break;
			}
		case ROOK:
			{
				
				(colour == WHITE) 
				? mWhitePieces.push_back(new Rook(position120, WHITE, firstMove)) :
				  mBlackPieces.push_back(new Rook(position120, BLACK, firstMove));
				
				break;
			}
		case QUEEN:
			{
				
				(colour == WHITE) 
				? mWhitePieces.push_back(new Queen(position120, WHITE, firstMove)) :
				  mBlackPieces.push_back(new Queen(position120, BLACK, firstMove));
				
				break;
			}
		case KING:
			{
				
				(colour == WHITE) 
				? mWhitePieces.push_back(new King(position120, WHITE, firstMove)) :
				  mBlackPieces.push_back(new King(position120, BLACK, firstMove));
				
				break;
			}

	}
}

void Board::removePiece(int position120)
{
}

void Board::movePiece()
{
}

Colour Board::getCurrPlayer()
{
	return mCurrPlayer;
}

void Board::setCurrPlayer(Colour colour)
{
	mCurrPlayer = colour;
}

bool Board::isCurrPlayerInCheck()
{
	return mCurrPlayerInCheck;
}

bool Board::isCurrPlayerInCheckmate()
{
	return mCurrPlayerInCheckmate;
}

