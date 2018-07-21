#include <bits/stdc++.h>

using namespace std;

int n, len;
vector <string> grid;
string s;
int dr[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dc[] = {1, 1, 0, -1, -1, -1, 0, 1};

inline bool isValid (const int r, const int c) {
  return 0 <= r and r < n and 0 <= c and c < n;
}

bool check (int r, int c, int pos, const int dir) {
  if (pos == len or grid[r][c] != s[pos]) return false;
  if (pos == len - 1) return true;
  int nr = r + dr[dir];
  int nc = c + dc[dir];
  if (not isValid(nr, nc)) return false;
  return check(nr, nc, pos + 1, dir);
}

void searchInGrid () {
  len = s.size();
  for (int r = 0; r < n; r++)
    for (int c = 0; c < n; c++)
      for (int d = 0; d < 8; d++)
        if (check(r, c, 0, d)) {
          len--;
          cout << r + 1 << ',' << c + 1 << ' ';
          cout << r + 1 + dr[d] * len << ',' << c + 1 + dc[d] * len << endl;
          return;
        }
  puts("Not found");
}

void processQueries () {
  while (cin >> s, s[0] != '0') searchInGrid();
}

void readGrid () {
  cin >> n;
  grid.resize(n);
  for (int r = 0; r < n; r++) {
    cin >> grid[r];
  }
}

int main () {
  readGrid();
  processQueries();
  return (0);
}
