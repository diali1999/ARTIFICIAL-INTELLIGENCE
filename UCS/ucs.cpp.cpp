#include<bits/stdc++.h> 
using namespace std;
void printSolution(int board[8][8]) 
{ 
	static int k = 1; 
	cout<<k++<<":"<<endl; 
	for (int i = 0; i < 8; i++) 
	{ 
		for (int j = 0; j < 8; j++) 
			cout <<" " << board[i][j] <<" "; 
	    cout <<endl; 
	} 
	cout <<endl; 
} 
bool isSafe(int board[8][8], int row, int col) 
{ 
	int i, j; 
	for (i = 0; i < col; i++) 
		if (board[row][i]) 
			return false; 
	for (i=row, j=col; i>=0 && j>=0; i--, j--) 
		if (board[i][j]) 
			return false; 
	for (i=row, j=col; j>=0 && i<8; i++, j--) 
		if (board[i][j]) 
			return false; 

	return true; 
} 
bool solve8QUtil(int board[8][8], int col) 
{ 
	if (col == 8) 
	{ 
		printSolution(board); 
		return true; 
	} 
	bool res = false; 
	for (int i = 0; i < 8; i++) 
	{ 
		if ( isSafe(board, i, col) ) 
		{ 
			board[i][col] = 1; 
			res = solve8QUtil(board, col + 1) || res; 
			board[i][col] = 0; 
		} 
	} 
	return res; 
} 
void solve8Q() 
{ 
	int board[8][8]; 
	memset(board, 0, sizeof(board)); 
    if (solve8QUtil(board, 0) == false) 
	{ 
		printf("Solution does not exist"); 
		return ; 
	} 
} 
int main() 
{ 
    cout<<"All probable solutions are:\n";
    solve8Q(); 
	return 0; 
} 

