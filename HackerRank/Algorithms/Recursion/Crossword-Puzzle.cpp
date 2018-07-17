/**
 * > Author: TISparta
 * > Date: 14-08-18
 * > Tags: Backtracking
 * > Difficulty: 4 / 10
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 10;
const char EMPTY = '-';
char FILLED;

vector <string> grid(N);
vector <string> words;
vector <bool> vis;
vector <vector <pair <int, int>>> moves;
bool found = false;

void print () {
  for (auto s: grid) cout << s << endl;
}

bool isFilled () {
  for (auto a: grid) for (auto b: a) if (b == EMPTY) return false;
  return true;
}

void reverseMove () {
  for (int i = 0; i < moves.back().size(); i++)
   grid[moves.back()[i].first][moves.back()[i].second] = EMPTY;
  moves.pop_back();
}

bool canPut (string s, int r, int c, bool horizontal) {
  if (horizontal) {
    int c1 = c, c2 = c;
    while (0 <= c1 - 1 and grid[r][c1 - 1] != FILLED) c1--;
    while (c2 + 1 < N and grid[r][c2 + 1] != FILLED) c2++;
    if (c2 - c1 + 1 != s.size()) return false;
    for (int i = 0; i < s.size(); i++)
      if (grid[r][c1 + i] != EMPTY and grid[r][c1 + i] != s[i]) return false;
    vector <pair <int, int>> move;
    for (int i = 0; i < s.size(); i++) {
      if (grid[r][c1 + i] == EMPTY) {
        grid[r][c1 + i] = s[i];
        move.push_back({r, c1 + i});
      }
    }
    moves.push_back(move);
    return true;
  }
  else {
    int r1 = r, r2 = r;
    while (0 <= r1 - 1 and grid[r1 - 1][c] != FILLED) r1--;
    while (r2 + 1 < N and grid[r2 + 1][c] != FILLED) r2++;
    if (r2 - r1 + 1 != s.size()) return false;
    for (int i = 0; i < s.size(); i++)
      if (grid[r1 + i][c] != EMPTY and grid[r1 + i][c] != s[i]) return false;
    vector <pair <int, int>> move;
    for (int i = 0; i < s.size(); i++) {
      if (grid[r1 + i][c] == EMPTY) {
        grid[r1 + i][c] = s[i];
        move.push_back({r1 + i, c});
      }
    }
    moves.push_back(move);
    return true;
  }
}

void backtrack (int r = 0, int c = 0) {
  if (r == N) {
    found |= isFilled();
    if (found) print();
  }
  if (found) return;
  if (grid[r][c] == EMPTY) {
    for (int i = 0; i < words.size(); i++) {
      if (vis[i]) continue;
      if (canPut(words[i], r, c, true)) {
        vis[i] = true;
        backtrack(c + 1 == N ? r + 1 : r, c + 1 == N ? 0 : c + 1);
        vis[i] = false;
        reverseMove();
      }
      if (canPut(words[i], r, c, false)) {
        vis[i] = true;
        backtrack(c + 1 == N ? r + 1 : r, c + 1 == N ? 0 : c + 1);
        vis[i] = false;
        reverseMove();
      }
    }
  }
  else {
    backtrack(c + 1 == N ? r + 1 : r, c + 1 == N ? 0 : c + 1);
  }
}

void read () {
  for (int r = 0; r < N; r++) cin >> grid[r];
  for (auto row: grid) for (auto ch: row) if (ch != EMPTY) FILLED = ch;
  cin.ignore();
  string word;
  while (getline(cin, word, ';')) {
    words.push_back(word);
    vis.push_back(false);
  }
}

int main () {
  read();
  backtrack();
  return (0);
}
