// UVA 439 Knight Moves
// Eric Abbott
// 10-20-17


#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
	struct point
	{
		int r;
		int c;
	};
	
	string strStart; // original input used in output
	string strEnd;
	point start;
	point end;
	point current;
	point newPoint;
	int moves;
	int currentMoves;
	queue<point> q; // points to process
	int board[8][8];
	int thisR, thisC;
	
	/*while (1)  // find the int value of a char
	{
		string c;
		cin >> c;
		int j = c[0];
		cout << j << strEndl;
	}*/
	
	while (cin >> strStart)
	{
		cin >> strEnd;
		moves = 0;
		
		if (strStart != strEnd)  // check for same point - moves would already be 0
		{
			// process input
			start.c = strStart[0] - 97; // char a is 97
			start.r = strStart[1] - 49; // char 1 is 49
			end.c = strEnd[0] - 97;
			end.r = strEnd[1] - 49;
			
			// initialize board
			for (int i = 0; i < 8; i++)
				for (int j = 0; j < 8; j++)
					board[i][j] = -1;
			
			board[start.r][start.c] = 0;
			q.push(start);
			
			// hard coded combinations of +- 1 and 2
			int row[] = {-2, -2, -1, -1,  1,  1,  2,  2};
			int col[] = {-1,  1, -2,  2, -2,  2, -1,  1};
			
			// process points
			while (board[end.r][end.c] == -1) // stops when end point has a value
			{
				current = q.front();
				q.pop();
				currentMoves = board[current.r][current.c] + 1;
				
				// check combos of +- 1 and 2, assign higher move count, enqueue new points
				
				for (int i = 0; i < 8; i++)
				{
					thisR = current.r + row[i];
					thisC = current.c + col[i];
					
					if (0 <= thisR && thisR <= 7 && 0 <= thisC && thisC <= 7 && board[thisR][thisC] == -1)
						// coords are valid and place doesn't already have a move count
					{
						board[ thisR ][ thisC ] = currentMoves;
						newPoint.r = thisR;
						newPoint.c = thisC;
						q.push(newPoint); // child to be processed
					}
				}
				
				if (0) { // set to 1 to see the numbers propagating
					string pauser;
					for (int a = 0; a < 8; a++)
					{
						for (int b = 0; b < 8; b++)
						{
							if (board[a][b] >= 0)
								cout << board[a][b] << ' ';
							else
								cout << "_ ";
						}
						cout << endl;
					}
					cin >> pauser;
				}
				
				// new points with next higher move count are now in queue
			}
			
			// end point now has output value. empty the queue
			moves = board[end.r][end.c];
			
			while (!q.empty())
				q.pop();
		}
		
		// moves would still be 0 for same start and end
		cout << "To get from " << strStart << " to " << strEnd << " takes " << moves << " knight moves." << endl;
	}
	
    return 0;
}

