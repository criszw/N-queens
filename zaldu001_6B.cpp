#include <map>
#include <iomanip>
#include <iostream>
#include <cmath>
#include <cstdlib>



	
	


include <iostream>
#include <vector>

using namespace std;

const char queen = 'Q';
const char capture = '.';
const char open = '-';


vector<vector<char>> fillBoard(int size) {
  vector<vector<char>> board;
  for(int i = 0; i < size; i++) {
    board.push_back(vector<char>());
    for (int j = 0; j < size; j++) { 
      board[i].push_back(open);
    }
  }
  return board;
}

void printBoard(vector<vector<char>> board) {
  cout << "Current Board:" << endl;
  for(int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board.size(); j++) {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

bool insertQueen(vector<vector<char>>& board, int x, int y) {
  board[x][y] = queen;
  // Fill row
  for (int i = 0; i < board.size(); i++) {
    if (board[x][i] == open) {
      board[x][i] = capture;
    }
  }
  // Fill column
  for (int i = 0; i < board.size(); i++) {
    if (board[i][y] == open) {
       board[i][y] = capture;      
    }
  }

  // Fill left to right diag
  int i = x;
  int j = y;
  while (i > 0 && j > 0) {
    i--;
    j--;
  }
  while (i < board.size() && j < board.size()) {
    if (board[i][j] == open) {
      board[i][j] = capture;
    }
    i++;
    j++;
  }
  
  // Fill right to left diag
  i = x;
  j = y;
  while (i > 0 && j < board.size() - 1) {
    i--;
    j++;
  }
  while (i < board.size() && j >= 0) {
    if (board[i][j] == open) {
      board[i][j] = capture;
    }
    i++;
    j--;
  }
  return true;
}

bool fillQueens(vector<vector<char>> board, int x, int y) {
  // Base cases
  if (x > 0) {
    insertQueen(board, x-1, y);
  }
  if (x == board.size()) {
    printBoard(board);
    return true;
  }
  
  // Recurse:
  for (int i = 0; i < board.size(); i++) {
    if (board[x][i] == open && fillQueens(board, x + 1, i)) {
      return true;
    }
  }
  return false;
}

int main() {
  // Fill board
	cout<< "What size board do you want?" << endl;
	int numQ, size;
	cin >> size;
	cout<< "How many queens do you want to place?" << endl;
	cin >> numQ;
	int board[size][size];
  int size = 5;
  vector<vector<char>> board = fillBoard(size);
  if (!fillQueens(board, 0, 0)) {
    cout << "No solution for size: " << size;
  }
  return 0;
}
