#include "knight.h"
#include "gameBitBoard.h"

Knight::Knight(int position120, Colour colour, bool firstMove) :
	Piece(position120, colour, KNIGHT, firstMove)
{
}

list<uint32_t> Knight::getPotentialMoves(GameBitBoard gameBitBoard)
{
	//printf("getting legal moves\n");
	list<uint32_t> moves;
	int num_direction = sizeof(direction)/sizeof(direction[0]);
	uint32_t testTile;
	uint32_t testTile64;
	uint32_t moveToAdd;
	for (int i =0; i<num_direction; i++)
	{
		moveToAdd = uint32_t(getPosition());
		testTile = getPosition()+direction[i];
			testTile64 = board120to64[testTile];
			if (isValidTile(testTile) )
			{
				if ( gameBitBoard.isTileFree(testTile64) )
				{
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
							moves.push_back(moveToAdd);

						}
					}
					else
					{
						if (gameBitBoard.isWhitePiece(testTile64))
						{
							moveToAdd |= (1<<14); //capture
							moveToAdd |= (testTile<<7);
							moves.push_back(moveToAdd);

						}
					}
				}
			}

	}

	return moves;
}
