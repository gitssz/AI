#include <bits/stdc++.h>
#define N 4
using namespace std;

//
void printSolution(int board[N][N])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
		if(board[i][j])
			cout << "Q ";
		else cout<<". ";  //empty squares
		printf("\n");
	}
}

bool isSafe(int board[N][N], int row, int col)
{
	int i, j;
	for (i = 0; i < col; i++)
		if (board[row][i])		//checking rowwise
			return false;		//queen is found n position is not safe
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)	//left diagonal
		if (board[i][j])		//
			return false;
	for (i = row, j = col; j >= 0 && i < N; i++, j--)
		if (board[i][j])			//right diagonal
			return false;	
	return true;
}

bool solveNQUtil(int board[N][N], int col) 
{ //placing queens on board column by column
	if (col >= N)
		return true;
	for (int i = 0; i < N; i++) {
		if (isSafe(board, i, col)) {
			board[i][col] = 1; 	//marks the square for queen
			if (solveNQUtil(board, col + 1))
				return true;
			board[i][col] = 0; //resetting square to 0
		}
	}
	return false;
}

bool solveNQ()
{
	int board[N][N] = { { 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 } };

	if (solveNQUtil(board, 0) == false) {
		cout << "Solution does not exist";
		return false;
	}

	printSolution(board);
	return true;
}

int main()
{
	solveNQ();
	return 0;
}
