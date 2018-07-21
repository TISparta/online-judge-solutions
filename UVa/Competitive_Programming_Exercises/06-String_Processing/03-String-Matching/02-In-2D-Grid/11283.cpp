#include <bits/stdc++.h>

using namespace std;

const int N = 4;
const char FILLED = '#';

vector <string> grid(N);
string s;
int dr[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dc[] = {1, 1, 0, -1, -1, -1, 0, 1};

inline bool isValid (const int r, const int c) {
  return 0 <= r and 0 <= c and r < N and c < N;
}

bool backtrack (int r, int c, int id = 1) {
  if (grid[r][c] != s[id - 1]) return false;
  if (id == s.size()) return true;
  char ch = grid[r][c];
  grid[r][c] = FILLED;
  bool ret = false;
  for (int d = 0; d < 8; d++) {
    int nr = r + dr[d];
    int nc = c + dc[d];
    if (isValid(nr, nc) and grid[nr][nc] != FILLED) {
      ret |= backtrack(nr, nc, id + 1);
    }
  }
  grid[r][c] = ch;
  return ret;
}

bool findInGrid () {
  for (int r = 0; r < N; r++)
    for (int c = 0; c < N; c++)
      if (backtrack(r, c)) return true;
  return false;
}

int getScore () {
  if (s.size() < 3) return 0;
  if (s.size() < 5) return 1;
  if (s.size() == 5) return 2;
  if (s.size() == 6) return 3;
  if (s.size() == 7) return 5;
  return 11;
}

int processQueries () {
  int k, score = 0;
  cin >> k;
  while (k--) {
    cin >> s;
    if (findInGrid()) score += getScore();
  }
  return score;
}

int main () {
  int tc;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    for (int r = 0; r < N; r++) cin >> grid[r];
    cout << "Score for Boggle game #" << t << ": " << processQueries() << endl;
  }
  return (0);
}
