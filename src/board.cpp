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

	mGameBitBoard.update(mWhitePieces, mBlackPieces, 120);

	
}

void Board::removePiece(int position120)
{
	list<Piece*> playerPieces;
	list<Piece*>::iterator piece_it;

	int position64 = board120to64[position120];

	mGameBitBoard.isWhitePiece(position64) ? 
		playerPieces = mWhitePieces : playerPieces = mBlackPieces;

	for(piece_it=playerPieces.begin(); piece_it != playerPieces.end(); piece_it++)
	{
		if ( (*piece_it)->getPosition() == position64 )
		{
			delete *piece_it;
			playerPieces.erase(piece_it);
			break;
		}
	}

	mGameBitBoard.update(mWhitePieces, mBlackPieces, 0);

}

void Board::movePiece(uint32_t move)
{
	uint32_t startPos = (move & 0x7f);
	uint32_t destPos = ((move>>7) & 0x7f);


	list<Piece*> playerPieces;
	list<Piece*>::iterator piece_it;

	mCurrPlayer == WHITE ? 
		playerPieces = mWhitePieces : playerPieces = mBlackPieces;

	for(piece_it = playerPieces.begin(); piece_it !=playerPieces.end(); piece_it++)
	{
		if( (*piece_it)->getPosition() == startPos)
		{
			if( (*piece_it)->isFirstMove() )
			{
				(*piece_it)->setFirstMoveFalse();
			}

			if (move >> 14)
			{
				removePiece(destPos);
			}

			(*piece_it)->setPosition(destPos);

			mGameBitBoard.update(mWhitePieces, mBlackPieces, 120);

			mCurrPlayer == WHITE ? mCurrPlayer = BLACK : mCurrPlayer = WHITE;

			break;
		}
	}

}

Colour Board::getCurrPlayer()
{
	return mCurrPlayer;
}

void Board::setCurrPlayer(Colour colour)
{
	mCurrPlayer = colour;
}

GameBitBoard Board::getGameBitBoard()
{
	return mGameBitBoard;
}

bool Board::isWhitePiece(int position64)
{
	return mGameBitBoard.isWhitePiece(position64);
}

bool Board::isBlackPiece(int position64)
{
	return mGameBitBoard.isBlackPiece(position64);
}

bool Board::isCurrPlayerInCheck()
{
	return mCurrPlayerInCheck;
}

bool Board::isCurrPlayerInCheckmate()
{
	return mCurrPlayerInCheckmate;
}

