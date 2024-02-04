#include <iostream>
#include <utility>
#include <vector>
using namespace std;
char board[8][8] = {{'_', 'o', '_', 'o', '_', 'o', '_', 'o'},
                    {'o', '_', 'o', '_', 'o', '_', 'o', '_'},
                    {'_', 'o', '_', 'o', '_', 'o', '_', 'o'},
                    {'_', '_', '_', '_', '_', '_', '_', '_'},
                    {'_', '_', '_', '_', '_', '_', '_', '_'},
                    {'x', '_', 'x', '_', 'x', '_', 'x', '_'},
                    {'_', 'x', '_', 'x', '_', 'x', '_', 'x'},
                    {'x', '_', 'x', '_', 'x', '_', 'x', '_'}};
pair<int, int> getSquare(const char *str) {
  int col = str[0] - 97;
  int row = (str[1] - 48) - 1;
  return pair<int, int>(row, col);
}
vector<pair<int, int>> getMoves(pair<int, int> &pos, int player) {
  int row = pos.first, col = pos.second;
  char square = board[row][col];
  vector<pair<int, int>> moves;
  if (player == 0) {
    switch (square) {
    case 'X':
      if (row + 1 < 8 && col - 1 >= 0 && board[row + 1][col - 1] == '_')
        moves.push_back(pair<int, int>(row + 1, col - 1));
      if (row + 1 < 8 && col + 1 < 8 && board[row + 1][col + 1] == '_')
        moves.push_back(pair<int, int>(row + 1, col + 1));
    case 'x':
      if (row - 1 >= 0 && col - 1 >= 0 && board[row - 1][col - 1] == '_')
        moves.push_back(pair<int, int>(row - 1, col - 1));
      if (row - 1 >= 0 && col + 1 < 8 && board[row - 1][col + 1] == '_')
        moves.push_back(pair<int, int>(row - 1, col + 1));
      break;
    default:
      break;
    }
  } else if (player == 1) {
    switch (square) {
    case 'O':
      if (row - 1 >= 0 && col - 1 >= 0 && board[row - 1][col - 1] == '_')
        moves.push_back(pair<int, int>(row - 1, col - 1));
      if (row - 1 >= 0 && col + 1 < 8 && board[row - 1][col + 1] == '_')
        moves.push_back(pair<int, int>(row - 1, col + 1));
    case 'o':
      if (row + 1 < 8 && col - 1 >= 0 && board[row + 1][col - 1] == '_')
        moves.push_back(pair<int, int>(row + 1, col - 1));
      if (row + 1 < 8 && col + 1 < 8 && board[row + 1][col + 1] == '_')
        moves.push_back(pair<int, int>(row + 1, col + 1));
      break;
    default:
      break;
    }
  }
  return moves;
}

int main() {
  int turn = 0;
  while (true) {
    cout << "    ";
    for (char c = 'a'; c <= 'h'; c++) {
      cout << c << "   ";
    }
    cout << endl;
    for (int i = 0; i < 8; i++) {
      cout << 1 + i << " | ";
      for (int j = 0; j < 8; j++) {
        cout << board[i][j] << " | ";
      }
      cout << endl << endl;
    }

    cout << "Player " << (turn % 2) + 1 << " select square: ";
    string move;
    cin >> move;
    pair<int, int> square = getSquare(move.c_str());
    vector<pair<int, int>> moves = getMoves(square, turn % 2);
    for (int i = 0; i < moves.size(); i++) {
      cout << i + 1 << ". " << (char)(moves[i].second + 97)
           << moves[i].first + 1 << endl;
    }
    if (moves.empty()) {
      cout << "No moves!" << endl;
    } else {
      cout << "Player " << (turn % 2) + 1 << " choose option: ";
      int option;
      cin >> option;
      pair<int, int> dest = moves[option - 1];
      board[dest.first][dest.second] = board[square.first][square.second];
      board[square.first][square.second] = '_';
      turn++;
    }
  }
}