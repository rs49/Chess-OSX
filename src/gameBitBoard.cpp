#include "gameBitBoard.h"

void GameBitBoard::update(list<Piece*> whitePieces, list<Piece*> blackPieces, int enPas)
{
	mWhiteBitBoard = 0;
	mBlackBitBoard = 0;

	list<Piece*>::iterator it;

	int position64;

	for( it=whitePieces.begin(); it !=whitePieces.end(); it++)
	{
		position64 = board120to64[ (*it)->getPosition() ];
		mWhiteBitBoard |= ( uint64_t(1) << position64 );

		if( (*it)->getPieceType() == KING )
		{
			mWhiteKingPosition120 = (*it)->getPosition();
		}
	}

	for( it=blackPieces.begin(); it !=blackPieces.end(); it++)
	{
		position64 = board120to64[ (*it)->getPosition() ];
		mBlackBitBoard |= ( uint64_t(1) << position64 );

		if( (*it)->getPieceType() == KING )
		{
			mBlackKingPosition120 = (*it)->getPosition();
		}
	}

	mBothBitBoards = mWhiteBitBoard | mBlackBitBoard;

	mEnPas = enPas;
}

bool GameBitBoard::isTileFree(int position64)
{
	if( ( uint64_t(1) << position64 ) & mBothBitBoards )
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool GameBitBoard::isWhitePiece(int position64)
{
	if( ( uint64_t(1) << position64 ) & mWhiteBitBoard )
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool GameBitBoard::isBlackPiece(int position64)
{
	if( ( uint64_t(1) << position64 ) & mBlackBitBoard )
	{
		return true;
	}
	else
	{
		return false;
	}
}

int GameBitBoard::getWhiteKing()
{
	return mWhiteKingPosition120;
}

int GameBitBoard::getBlackKing()
{
	return mBlackKingPosition120;
}

int GameBitBoard::getEnPas()
{
	return mEnPas;
}

void GameBitBoard::setEnPas(int square120)
{
	mEnPas = square120;
}
	
