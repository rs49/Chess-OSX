#include "game.h"
#include "global_init.h"
//#include "piece.h"
//#include <SDL2/SDL.h>
//#include <SDL2_image/SDL_image.h>


void Game::newBoard()
{
	mBoard.addPiece(21, WHITE, ROOK, true);
	mBoard.addPiece(22, WHITE, KNIGHT, true);
	mBoard.addPiece(23, WHITE, BISHOP, true);
	mBoard.addPiece(24, WHITE, QUEEN, true);
	mBoard.addPiece(25, WHITE, KING, true);
	mBoard.addPiece(26, WHITE, BISHOP, true);
	mBoard.addPiece(27, WHITE, KNIGHT, true);
	mBoard.addPiece(28, WHITE, ROOK, true);

	for (int i = 31; i< (31+8); i++)
	{
		mBoard.addPiece(i, WHITE, PAWN, true);
	}


	mBoard.addPiece(91, BLACK, ROOK, true);
	mBoard.addPiece(92, BLACK, KNIGHT, true);
	mBoard.addPiece(93, BLACK, BISHOP, true);
	mBoard.addPiece(94, BLACK, QUEEN, true);
	mBoard.addPiece(95, BLACK, KING, true);
	mBoard.addPiece(96, BLACK, BISHOP, true);
	mBoard.addPiece(97, BLACK, KNIGHT, true);
	mBoard.addPiece(98, BLACK, ROOK, true);

	for (int i = 81; i< (81+8); i++)
	{
		mBoard.addPiece(i, BLACK, PAWN, true);
	}

	mBoard.setCurrPlayer(WHITE);
	mSelectedTile = 120;
	mSelectedPiece = 0;

}

void Game::selectTile(int position)
{
	// If the same tile is selected, turn it off
	if(position == mSelectedTile)
	{
		position = 120;
		mSelectedPiece =0;
	}
	else if(mSelectedPiece)
	{
		list<Piece*> playerPieces;
		list<Piece*>::iterator piece_it;

		(mBoard.getCurrPlayer() == WHITE)
		? playerPieces = mBoard.getWhitePieces() :
		  playerPieces = mBoard.getBlackPieces();
		
		// find the piece
		for(piece_it=playerPieces.begin(); piece_it != playerPieces.end(); piece_it++)
		{
			if( board120to64[ (*piece_it)->getPosition() ] == mSelectedTile)
			{
				list<uint32_t>::iterator move_it;
				list<uint32_t> moveList = (*piece_it)->getLegalMoves(&mBoard);

				for(move_it=moveList.begin(); move_it != moveList.end(); move_it++)
				{
					printf("%lu\n",moveList.size());
					if( board120to64[ ((*move_it)>>7)&0x7f ] == position)
					{
						mBoard.movePiece(*move_it);
						position = 120;
						mSelectedPiece = 0;
						break;
					}
				}
			}
		}
	}
	

	mSelectedTile = position;

	if(mBoard.isWhitePiece(position))
	{
		mSelectedPiece = 1;
	}
	else if (mBoard.isBlackPiece(position))
	{
		mSelectedPiece = 1;
	}
	else
	{
		mSelectedPiece = 0;
	}
}

void Game::drawBoard()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);

	SDL_Rect tile = { 0, 0, TILE_SIZE, TILE_SIZE};

	// Draw tiled board

	for(int i = 0; i < 64; i++)
	{
		tile.x = TILE_SIZE * (i%8);

		tile.y = TILE_SIZE * (7-i/8);
		if( mSelectedTile == i)
		{
			SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);

		}
		else if(tile_colour[i] == 0)
		{
			SDL_SetRenderDrawColor(renderer, 162, 103, 0, 0);
		}
		else
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		}

		SDL_RenderFillRect(renderer, &tile);
	}

	// draw moves for potential moves
	list<Piece*>::iterator it;
	list<Piece*> currList;

	list<uint32_t> moveList;
	list<uint32_t>::iterator move_it;
	int position64;
	
	if(mSelectedPiece)
	{
		SDL_SetRenderDrawColor(renderer, 50, 50, 200, 0);

		(mBoard.getCurrPlayer() == WHITE)
		? currList = mBoard.getWhitePieces() :
		  currList = mBoard.getBlackPieces();

		for(it = currList.begin(); it != currList.end(); it++)
		{
			if( board120to64[ (*it)->getPosition() ] == mSelectedTile )
			{
				moveList = (*it)->getLegalMoves(&mBoard);
				break;
			}
		}

		for(move_it = moveList.begin(); move_it != moveList.end(); move_it++)
		{
			position64 = board120to64[  ((*move_it)>>7)&0x7f ];
			//printf("%lu\n", position64);

			tile.x = TILE_SIZE*(position64%8);
			tile.y = TILE_SIZE*(7-position64/8);

			SDL_RenderFillRect(renderer, &tile);
		}
	}
	
	//draw the pieces on the board
	//drawPiece(WHITE, ROOK, 22);
	
	currList = mBoard.getWhitePieces();
	for( it=currList.begin(); it != currList.end(); it++ )
	{
		drawPiece( (*it)->getColour(), (*it)->getPieceType(), (*it)->getPosition() );
	}

	currList = mBoard.getBlackPieces();
	for( it=currList.begin(); it != currList.end(); it++ )
	{
		drawPiece( (*it)->getColour(), (*it)->getPieceType(), (*it)->getPosition() );
	}
	

	
	SDL_RenderPresent(renderer);


}

void Game::drawPiece(Colour colour, PieceType pieceType, int position120)
{
	int x, y, position64;

	position64 = board120to64[position120];

	x = position64%8;
	y = 7-position64/8;

	SDL_Rect renderQuad = { x*TILE_SIZE, y*TILE_SIZE, TILE_SIZE, TILE_SIZE };

	switch(pieceType)
	{
		case PAWN:
			{
				(colour == WHITE)
				? SDL_RenderCopy(renderer, mWhitePawnTexture, NULL, &renderQuad) :
				  SDL_RenderCopy(renderer, mBlackPawnTexture, NULL, &renderQuad);

				break;
				  
			}
		case KNIGHT:
			{
				(colour == WHITE)
				? SDL_RenderCopy(renderer, mWhiteKnightTexture, NULL, &renderQuad) :
				  SDL_RenderCopy(renderer, mBlackKnightTexture, NULL, &renderQuad);

				break;
				  
			}
		case BISHOP:
			{
				(colour == WHITE)
				? SDL_RenderCopy(renderer, mWhiteBishopTexture, NULL, &renderQuad) :
				  SDL_RenderCopy(renderer, mBlackBishopTexture, NULL, &renderQuad);

				break;
				  
			}
		case ROOK:
			{
				(colour == WHITE)
				? SDL_RenderCopy(renderer, mWhiteRookTexture, NULL, &renderQuad) :
				  SDL_RenderCopy(renderer, mBlackRookTexture, NULL, &renderQuad);

				break;
				  
			}
		case QUEEN:
			{
				(colour == WHITE)
				? SDL_RenderCopy(renderer, mWhiteQueenTexture, NULL, &renderQuad) :
				  SDL_RenderCopy(renderer, mBlackQueenTexture, NULL, &renderQuad);

				break;
				  
			}
		case KING:
			{
				(colour == WHITE)
				? SDL_RenderCopy(renderer, mWhiteKingTexture, NULL, &renderQuad) :
				  SDL_RenderCopy(renderer, mBlackKingTexture, NULL, &renderQuad);

				break;
				  
			}
	}
}

void Game::initAssets()
{
	loadTexture(&mWhitePawnTexture,"60_png/WhitePawn.png");
	loadTexture(&mWhiteKnightTexture,"60_png/WhiteKnight.png");
	loadTexture(&mWhiteBishopTexture,"60_png/WhiteBishop.png");
	loadTexture(&mWhiteRookTexture,"60_png/WhiteRook.png");
	loadTexture(&mWhiteQueenTexture,"60_png/WhiteQueen.png");
	loadTexture(&mWhiteKingTexture,"60_png/WhiteKing.png");

	loadTexture(&mBlackPawnTexture,"60_png/BlackPawn.png");
	loadTexture(&mBlackKnightTexture,"60_png/BlackKnight.png");
	loadTexture(&mBlackBishopTexture,"60_png/BlackBishop.png");
	loadTexture(&mBlackRookTexture,"60_png/BlackRook.png");
	loadTexture(&mBlackQueenTexture,"60_png/BlackQueen.png");
	loadTexture(&mBlackKingTexture,"60_png/BlackKing.png");
}

void Game::loadTexture(SDL_Texture **targetTexture, string pathName)
{
	SDL_Surface *surface = IMG_Load(pathName.c_str());
	if(surface == NULL)
	{
		printf("Failed load surface\n");
	}
	
	//SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 0, 0xff, 0
	
	*targetTexture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	if( targetTexture == NULL )
	{
		printf("Failed loading texture: %s\n%s\n", pathName.c_str(), SDL_GetError());
	}
}
