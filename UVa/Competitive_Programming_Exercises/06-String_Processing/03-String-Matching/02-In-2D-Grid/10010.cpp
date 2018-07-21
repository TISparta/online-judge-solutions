#include <bits/stdc++.h>

using namespace std;

int n, m;
vector <string> grid;
string s;
int dr[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dc[] = {1, 1, 0, -1, -1, -1, 0, 1};

inline bool isValid (const int r, const int c) {
  return 0 <= r and r < n and 0 <= c and c < m;
}

bool check (int r, int c, int pos, const int dir) {
  if (pos == s.size() or grid[r][c] != s[pos]) return false;
  if (pos == s.size() - 1) return true;
  int nr = r + dr[dir];
  int nc = c + dc[dir];
  if (not isValid(nr, nc)) return false;
  return check(nr, nc, pos + 1, dir);
}

void processQueries () {
  int k;
  cin >> k;
  while (k--) {
    cin >> s;
    transform(begin(s), end(s), begin(s), ::tolower);
    for (int r = 0; r < n; r++) {
      for (int c = 0; c < m; c++) {
        bool ok = false;
        for (int d = 0; d < 8 and not ok; d++)
          if (check(r, c, 0, d)) ok = true;
        if (ok) {
          cout << r + 1 << ' ' << c + 1 << endl;
          r = n, c = m;
        }
      }
    }
  }
}

void readGrid () {
  cin >> n >> m;
  grid.resize(n);
  for (int r = 0; r < n; r++) {
    cin >> grid[r];
    transform(begin(grid[r]), end(grid[r]), begin(grid[r]), ::tolower);
  }
}

int main () {
  int tc;
  cin >> tc;
  while (tc--) {
    readGrid();
    processQueries();
    if (tc) puts("");
  }
  return (0);
}
