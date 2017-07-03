#include "queen.h"
#include "gameBitBoard.h"

Queen::Queen(int position120, Colour colour, bool firstMove) :
	Piece(position120, colour, QUEEN, firstMove)
{
}

/*
 * move structure:
 * bits 0-6: 	the inital position.
 * bits 7-13: 	the destination position
 * bit 	14: 	determines if it is capturing an enemy piece
 *
 * Attacking moves are at the begining of the list and passive (non-capturing)
 * moves are at the end of the list. This is for future AI.
 */ 


list<uint32_t> Queen::getPotentialMoves(GameBitBoard gameBitBoard)
{
		
	list<uint32_t> moves;
	int num_direction = sizeof(direction)/sizeof(direction[0]);
	int testTile;
	int testTile64;
	uint32_t moveToAdd;



	for (int i =0; i<num_direction; i++)
	{
		//moveToAdd = uint32_t(getPosition());
		testTile = getPosition();
		while(1)
		{
			moveToAdd = uint32_t(getPosition());
			testTile = testTile+direction[i];
			testTile64 = board120to64[testTile];
			if (isValidTile(testTile) )
			{
				if ( gameBitBoard.isTileFree(testTile64) )
				{
					//moveToAdd |= (testTile<<7);
					moves.push_back(moveToAdd | (testTile<<7));
								}
				else 
				{
					if (getColour() == WHITE)
					{
						if (gameBitBoard.isBlackPiece(testTile64))
						{
							moveToAdd |= (1<<14); //capture
							moveToAdd |= (testTile<<7);
							moves.push_back(moveToAdd);										}
					}
					else
					{
						if (gameBitBoard.isWhitePiece(testTile64))
						{
							moveToAdd |= (1<<14); //capture
							moveToAdd |= (testTile<<7);
							moves.push_back(moveToAdd);										}
					}
					break;
				}
			}
			else
			{
				break;
			}
		}
	}

	return moves;
}
