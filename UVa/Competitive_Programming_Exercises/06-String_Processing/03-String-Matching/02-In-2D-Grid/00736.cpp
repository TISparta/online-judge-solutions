#include <bits/stdc++.h>

using namespace std;

const char EMPTY = ' ';
const vector <string> dir = {"N", "NE", "E", "SE", "S", "SW", "W", "NW"};

int n;
string s;
vector <string> grid;
int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

inline bool isValid (const int r, const int c) {
  return 0 <= r and 0 <= c and r < n and c < n;
}

bool check (int r, int c, int id, const int d) {
  if (grid[r][c] != s[id - 1]) return false;
  if (id == s.size()) return true;
  while (true) {
    int nr = r + dr[d];
    int nc = c + dc[d];
    if (not isValid(nr, nc)) return false;
    if (grid[nr][nc] != EMPTY) return check(nr, nc, id + 1, d);
    r = nr, c = nc;
  }
}

void searchInGrid () {
  bool found = false;
  puts("");
  cout << s << endl;
  for (int r = 0; r < n; r++)
    for (int c = 0; c < n; c++)
      for (int d = 0; d < 8; d++)
        if (check(r, c, 1, d)) {
          found = true;
          cout << '(' << r + 1 << ',' << c + 1 << ") - " << dir[d] << endl;
        }
  if (not found) puts("not found");
}

void processQueries () {
  while (getline(cin, s), not s.empty()) {
    searchInGrid();
  }
}

void readGrid () {
  cin >> n;
  cin.ignore();
  grid.resize(n);
  for (int r = 0; r < n; r++) getline(cin, grid[r]);
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
