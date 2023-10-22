#include<iostream>
#include<vector>
using namespace std;

/*
  => path closed
  => out of bound
  => check is position is already visited
*/
bool isSafe(int maze[][4], int srcx, int srcy, int newX, int newY, int row, int col, vector<vector<bool>> &visited) {
  if (
    (newX >=0 && newX < row) && 
    (newY >= 0 && newY < col) &&
    maze[newX][newY] == 1  &&
    visited[newX][newY] == false
  ) {
    return true;
  }else {
    return false;
  }
}

void printAllPath(int maze[][4], int row, int col, int srcX, int srcY, string &output, vector<vector<bool>> &visited ) {

  // BASE CASE
  // Destination co-ordinates are [row-1] [col-1]
  if(srcX == row-1 && srcY == col - 1) {
    // Reached to destination
    cout << output << endl;
    return;
  }

  // Need to move in all directions no need to fallow order

  // UP
  int newX = srcX - 1;
  int newY = srcY;
  if(isSafe(maze, srcX, srcY, newX, newY, row, col, visited )) {
    // mark visited
    visited[newX][newY] = true;
    // recursion call
    output.push_back('U');
    printAllPath(maze, row, col, newX, newY, output, visited);
    // Backtracking
    output.pop_back();
    visited[newX][newY] = false;
  }

  // RIGHT  
  newX = srcX;
  newY = srcY+1;
  if(isSafe(maze, srcX, srcY, newX, newY, row, col, visited )) {
    // mark visited
    visited[newX][newY] = true;
    // recursion call
    output.push_back('R');
    printAllPath(maze, row, col, newX, newY, output, visited);
    // Backtracking
    output.pop_back();
    visited[newX][newY] = false;
  }
  // DOWN
  newX = srcX+1;
  newY = srcY;
  if(isSafe(maze, srcX, srcY, newX, newY, row, col, visited )) {
    // mark visited
    visited[newX][newY] = true;
    // recursion call
    output.push_back('D');
    printAllPath(maze, row, col, newX, newY, output, visited);
    // Backtracking
    output.pop_back();
    visited[newX][newY] = false;
  }
  // LEFT
  newX = srcX-1;
  newY = srcY;
  if(isSafe(maze, srcX, srcY, newX, newY, row, col, visited )) {
    // mark visited
    visited[newX][newY] = true;
    // recursion call
    output.push_back('L');
    printAllPath(maze, row, col, newX, newY, output, visited);
    // Backtracking
    output.pop_back();
    visited[newX][newY] = false;
  }
}


 
int main() {

  int maze[4][4] = {
    {1, 0, 0, 0},
    {1, 1, 0, 0},
    {1, 1, 1, 0},
    {1, 1, 1, 1},
  };

  int row = 4;
  int col = 4;

  int srcX = 0;
  int srcY = 0;
  string output = "";

  // create a visited array
  vector<vector<bool>> visited(row, vector<bool>(col, false)); 

  // If maze is closed
  if(maze[0][0] == 0) {
    cout << "No path exists" << endl;
  }else {
    visited[srcX][srcY] = true;
    printAllPath(maze, row, col, srcX, srcY, output, visited);
  }

  return 0;
}

/*
  OUTPUT
  
  DRDRDR
  DRDDRR
  DDRRDR
  DDRDRR
  DDDRURDR
  DDDRRR
  DDDRLRDR
*/