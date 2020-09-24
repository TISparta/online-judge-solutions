// Brute Force
// 2
// 24-12-2018

#include <bits/stdc++.h>

using namespace std;

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n, m, k;
  cin >> n >> m >> k;
  vector <vector <string>> grid(n + 1, vector <string> (m + 1, "")); 
  while (k--) {
    int type;
    cin >> type;
    if (type == 1) {
      int x, y;
      string id;
      cin >> x >> y >> id;
      bool found = false;
      int r = x, c = y;
      while (r <= n and not found) {
        if (grid[r][c] == "") {
          grid[r][c] = id;
          found = true;
        }
        c++;
        if (c == m + 1) c = 1, r++;
      }
    }
    else {
      string id;
      cin >> id;
      pair <int, int> ans(-1, -1);
      for (int r = 1; r <= n; r++) for (int c = 1; c <= m; c++) if (grid[r][c] == id) ans = {r, c};
      if (ans.first != -1) grid[ans.first][ans.second] = "";
      cout << ans.first << ' ' << ans.second << endl;
    }
  }
  return (0);
}
