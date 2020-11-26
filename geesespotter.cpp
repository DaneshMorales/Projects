#include "geesespotter_lib.h"

char * createBoard(std::size_t xdim, std::size_t ydim)
{
	std::size_t size = xdim*ydim;
	std::size_t capacity{size};
	char *board = new char[capacity];
	for (std::size_t k{0}; k<capacity; ++k )
	{
		board[k]=0;
	}
	return board;
}
void computeNeighbors(char * board, std::size_t xdim, std::size_t ydim)
{
	int elements = xdim*ydim;
	for (int m{0}; m<elements; ++m)
	{

		if (ydim == 1 || xdim == 1)
		{
			if ((m == 0) && (board[m] ==0))
			{
				if (board[1] == 9)
				{
					board[m]+=1;
				}
			}
			else if ((m == elements-1) && board[m]==0)
			{
				if (board[elements-2] ==0)
				{
					board[m] += 1;
				}
			}
			else
			{
				if (board[m+1] == 9 && board[m] != 9)
				{
					board[m]+=1;
				}
				if (board[m-1] == 9 && board[m] != 9)
				{
					board[m]+=1;
				}

			}

		}
		else
		{
			// top left corner
			if ((m == 0) && (board[m] ==0))
			{
				if (board[1] == 9)
				{
					board[m]+=1;
				}
				if (board[xdim] == 9)
				{
					board[m]+=1;
				}
				if (board[xdim+1] == 9)
				{
					board[m]+=1;
				}

			// top right corner
			}
			else if ((m == xdim-1) && (board[m] ==0))
			{
				if (board[m-1] == 9)
				{
					board[m]+=1;
				}
				if (board[m+xdim] == 9)
				{
					board[m]+=1;
				}
				if (board[m+xdim-1] == 9)
				{
					board[m]+=1;
				}
			}

			// bottom left corner
			else if ((m == elements - xdim) && (board[m] ==0))
			{
				if (board[m + 1] == 9)
				{
					board[m]+=1;
				}
				if (board[m-xdim] == 9)
				{
					board[m]+=1;
				}
				if (board[m-xdim+1] == 9)
				{
					board[m]+=1;
				}
			}

			//bottom right corner
			else if ((m == elements-1) && (board[m] ==0))
			{
				if (board[m-1] == 9)
				{
					board[m]+=1;
				}
				if (board[m-xdim-1] == 9)
				{
					board[m]+=1;
				}
				if (board[m-xdim] == 9)
				{
					board[m]+=1;
				}
			}

			// top border w/o corners
			else if ((m>=1) && (m<xdim-1) && (board[m] ==0))
			{
				if(board[m+xdim] == 9)
				{
					board[m]+= 1;
				}
				if(board[m+xdim+1] == 9)
				{
					board[m]+= 1;
				}
				if(board[m+xdim-1] == 9)
				{
					board[m]+= 1;
				}
				if(board[m+1] == 9)
				{
					board[m]+= 1;
				}
				if(board[m-1] == 9)
				{
					board[m]+= 1;
				}
			}

			// bottom border w/o corners
			else if((m>(elements-xdim)) && (m<(elements-1)) && (board[m] ==0))
			{
				if(board[m-xdim] == 9)
				{
					board[m]+= 1;
				}
				if(board[m-xdim+1] == 9)
				{
					board[m]+= 1;
				}
				if(board[m-xdim-1] == 9)
				{
					board[m]+= 1;
				}
				if(board[m+1] == 9)
				{
					board[m]+= 1;
				}
				if(board[m-1] == 9)
				{
					board[m]+= 1;
				}
			}

			// left border w/o corners

			else if((m > 1) && (m<elements-xdim) && (m%xdim ==0) && board[m] ==0)
			{
				if(board[m-xdim] == 9)
				{
					board[m]+= 1;
				}
				if(board[m+xdim] == 9)
				{
					board[m]+= 1;
				}
				if(board[m-xdim+1] == 9)
				{
					board[m]+= 1;
				}
				if(board[m+1] == 9)
				{
					board[m]+= 1;
				}
				if(board[m+xdim+1] == 9)
				{
					board[m]+= 1;
				}
			}

			// right border w/o corners

			else if((m > xdim) && (m<elements-1) && ((m+1)%xdim ==0) && (board[m] ==0))
			{
				if(board[m-xdim] == 9)
				{
					board[m]+= 1;
				}
				if(board[m+xdim] == 9)
				{
					board[m]+= 1;
				}
				if(board[m-xdim-1] == 9)
				{
					board[m]+= 1;
				}
				if(board[m-1] == 9)
				{
					board[m]+= 1;
				}
				if(board[m+xdim-1] == 9)
				{
					board[m]+= 1;
				}
			}

			//all the rest on the center
			else
			{

				if (board[m+1] == 9 && board[m] != 9)
				{
					board[m]+=1;
				}
				if (board[m-1] == 9 && board[m] != 9)
				{
					board[m]+=1;
				}
				if (board[m-xdim] == 9 && board[m] != 9)
				{
					board[m]+=1;
				}
				if (board[m-xdim+1] == 9 && board[m] != 9)
				{
					board[m]+=1;
				}
				if (board[m-xdim -1] == 9 && board[m] != 9)
				{
					board[m]+=1;
				}
				if (board[m+xdim] == 9 && board[m] != 9)
				{
					board[m]+=1;
				}
				if (board[m+xdim + 1] == 9 && board[m] != 9)
				{
					board[m]+=1;
				}
				if (board[m+xdim - 1] == 9 && board[m] != 9)
				{
					board[m]+=1;
				}

			}
	    }
	}
}
void hideBoard(char * board, std::size_t xdim, std::size_t ydim)
{
	unsigned int m{hiddenBit()};
	for (int k{0}; k< xdim*ydim; ++k)
	{
	board[k] |= m;
	}
}
void cleanBoard(char * board)
{
	delete[] board;
	board = nullptr;
}
void printBoard(char * board, std::size_t xdim, std::size_t ydim)
{
	int elements = xdim*ydim;

		for (int m{0}; m<elements; ++m)
		{
			if ((m+1) % xdim == 0)
			{
				if ((board[m] & markedBit()) == markedBit())
				{
					std::cout << " M " <<std::endl;
				}
				else if ((board[m] & hiddenBit()) == hiddenBit())
				{
					std::cout << " * " << std::endl;
				}
				else if (board[m] == 0)
				{
					std::cout << " 0 " <<std::endl;
				}
				else if (board[m] == 9)
				{
					std::cout << " 9 " << std::endl;
				}
				else if (board[m] == 8)
				{
					std::cout << " 8 " << std::endl;
				}
				else if (board[m] == 7)
				{
					std::cout << " 7 " << std::endl;
				}
				else if (board[m] == 6)
				{
					std::cout << " 6 " << std::endl;
				}
				else if (board[m] == 5)
				{
					std::cout << " 5 " << std::endl;
				}
				else if (board[m] == 4)
				{
					std::cout << " 4 " << std::endl;
				}
				else if (board[m] == 3)
				{
					std::cout << " 3 " << std::endl;
				}
				else if (board[m] == 2)
				{
					std::cout << " 2 " << std::endl;
				}
				else if (board[m] == 1)
				{
					std::cout << " 1 " << std::endl;
				}
			}
			else
			{
				if ((board[m] & markedBit()) == markedBit())
				{
					std::cout << " M ";
				}
				else if ((board[m] & hiddenBit()) == hiddenBit())
				{
					std::cout << " * ";
				}
				else if (board[m] == 0)
				{
					std::cout << " 0 ";
				}
				else if (board[m] == 9)
				{
					std::cout <<" 9 ";
				}
				else if (board[m] == 8)
				{
					std::cout << " 8 ";
				}
				else if (board[m] == 7)
				{
					std::cout << " 7 ";
				}
				else if (board[m] == 6)
				{
					std::cout << " 6 ";
				}
				else if (board[m] == 5)
				{
					std::cout << " 5 ";
				}
				else if (board[m] == 4)
				{
					std::cout << " 4 ";
				}
				else if (board[m] == 3)
				{
					std::cout << " 3 ";
				}
				else if (board[m] == 2)
				{
					std::cout << " 2 ";
				}
				else if (board[m] == 1)
				{
					std::cout << " 1 ";
				}

			}
		}

}
int reveal(char * board, std::size_t xdim, std::size_t ydim, std::size_t xloc, std::size_t yloc)
{
	unsigned int n{hiddenBit()};
	unsigned int m{markedBit()};
	int elements{xdim*ydim};
	if ((board[xdim*yloc + xloc] & m) == m)
	{
		return 1;
	}
	else if ((board[xdim*yloc + xloc] & n) == 0)
	{
		return 2;
	}
	else
	{
		board[xdim*yloc + xloc] &= ~n;

		if(board[xdim*yloc + xloc] == 9)
		{
			return 9;
		}
		else if (board[xdim*yloc + xloc] == 0)
		{
			int m{xdim*yloc + xloc};

			if (ydim == 1 || xdim == 1)
			{
				if (m == 0)
				{
					board[1] &= ~n;

				}
				else if (m == elements-1)
				{
					board[m-2] &= ~n;

				}
				else
				{
					board[m+1] &= ~n;

					board[m-1] &= ~n;

				}

			}
			else
			{
				// top left corner
				if (m == 0)
				{
					board[1] &= ~n;

					board[xdim] &= ~n;

					board[xdim+1] &= ~n;
				}
				// top right corner
				else if (m == xdim-1)
				{
					board[m-1] &= ~n;

					board[m+xdim] &= ~n;

					board[m+xdim-1] &= ~n;
				}

				// bottom left corner
				else if (m == elements - xdim)
				{
					board[m + 1] &= ~n;

					board[m-xdim] &= ~n;

					board[m-xdim+1] &= ~n;
				}

				//bottom right corner
				else if (m == elements-1)
				{
					board[m-1] &= ~n;

					board[m-xdim-1] &= ~n;

					board[m-xdim] &= ~n;

				}

				// top border w/o corners
				else if ((m>=1) && (m<xdim-1))
				{
					board[m+xdim] &= ~n;

					board[m+xdim+1] &= ~n;

					board[m+xdim-1] &= ~n;

					board[m+1] &= ~n;

					board[m-1] &= ~n;

				}

				// bottom border w/o corners
				else if((m>(elements-xdim)) && (m<(elements-1)))
				{
					board[m-xdim] &= ~n;

					board[m-xdim+1] &= ~n;

					board[m-xdim-1] &= ~n;

					board[m+1] &= ~n;

					board[m-1] &= ~n;

				}

				// left border w/o corners

				else if((m > 1) && (m<elements-xdim) && (m%xdim ==0))
				{
					board[m-xdim] &= ~n;

					board[m+xdim] &= ~n;

					board[m-xdim+1] &= ~n;

					board[m+1] &= ~n;

					board[m+xdim+1] &= ~n;

				}

				// right border w/o corners

				else if((m > xdim) && (m<elements-1) && ((m+1)%xdim ==0))
				{
					board[m-xdim] &= ~n;

					board[m+xdim] &= ~n;

					board[m-xdim-1] &= ~n;

					board[m-1] &= ~n;

					board[m+xdim-1] &= ~n;

				}

				//all the rest on the center
				else
				{

					board[m+1] &= ~n;

					board[m-1]&= ~n;

					board[m-xdim] &= ~n;

					board[m-xdim+1] &= ~n;

					board[m-xdim -1] &= ~n;

					board[m+xdim] &= ~n;

					board[m+xdim + 1] &= ~n;

					board[m+xdim - 1] &= ~n;


				}
			}
			return 0;
		}
		else
		{
			return 0;
		}
	}



}
int mark(char * board, std::size_t xdim, std::size_t ydim, std::size_t xloc, std::size_t yloc)
{
	unsigned int m{markedBit()};
	unsigned int n{hiddenBit()};
	if ((board[xdim*yloc + xloc] & n) == 0)
	{
		return 2;
	}
	else
	{
		if((board[xdim*yloc + xloc] & m) == m)
		{
			board[xdim*yloc + xloc] &= ~m;
		}
		else
		{
			board[xdim*yloc + xloc] |= m;
		}

		return 0;
	}

}
bool isGameWon(char * board, std::size_t xdim, std::size_t ydim)
{
	unsigned int m{markedBit()};
	unsigned int n{hiddenBit()};
	unsigned int nine{0b1001};
	unsigned int geese{0};
	int size{xdim*ydim};
	unsigned int count{0};

	for (int x{0}; x<size; ++x)
	{

		if ((board[x] & nine) == nine)
		{
			if(board[x] == 0b00101001)
			{
				++geese;
			}
			else
			{
				continue;
			}
		}
		else
		{
			if ((board[x] & n) == n)
			{
				++count;
			}
			else
			{
				continue;
			}
		}
	}

	if (geese == size)
	{
		return false;
	}
	else
	{
		if (count == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
