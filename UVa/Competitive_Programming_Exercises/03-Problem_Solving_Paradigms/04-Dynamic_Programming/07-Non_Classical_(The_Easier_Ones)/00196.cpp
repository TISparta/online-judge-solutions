#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1000 + 5, MAX_M = 18278 + 5, INF = 1e7;

int n, m, table[MAX_N][MAX_M];
vector <pair <int, int>> formula[MAX_N][MAX_M];

int dp (int r, int c) {
  if (table[r][c] != INF) return table[r][c];
  int ret = 0;
  for (auto pp: formula[r][c]) {
    ret += dp(pp.first, pp.second);
  }
  return table[r][c] = ret;
}

void printCase () {
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < m; c++) {
      if (c) cout << ' ';
      cout << dp(r, c);
    }
    cout << endl;
  }
}

void addFormula (int r, int c, string cell) {
  formula[r][c].clear();
  for (int i = 1; i < cell.size(); i++) {
    int col = 0, row = 0;
    while (isalpha(cell[i])) {
      col = col * 26 + (cell[i] - 'A' + 1);
      i++;
    }
    while (i < cell.size() and cell[i] != '+') {
      row = row * 10 + (cell[i] - '0');
      i++;
    }
    formula[r][c].push_back({row - 1, col - 1});
  }
}

void clearCase () {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      table[i][j] = INF;
}

void readCase () {
  cin >> m >> n;
  clearCase();
  cin.ignore();
  for (int r = 0; r < n; r++) {
    string line, cell;
    getline(cin, line);
    istringstream token(line);
    for (int c = 0; c < m; c++) {
      token >> cell;
      if (cell[0] == '=') {
        addFormula(r, c, cell);
      }
      else {
        table[r][c] = stoi(cell);
      }
    }
  }
}

int main () {
  int tc;
  cin >> tc;
  while (tc--) {
    readCase();
    printCase();
  }
  return (0);
}
