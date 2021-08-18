// Tags: BFS
// Difficulty: 3.0
// Priority: 5
// Date: 24-12-2018

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

const vector <int> dx = {1, -1, 0, 0};
const vector <int> dy = {0, 0, -1, 1};

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n, m;
  cin >> n >> m;
  vector <vector <int>> dis(n + 1, vector <int> (m + 1, INF));
  int k;
  cin >> k;
  queue <pair <int, int>> Q;
  while (k--) {
    int x, y;
    cin >> x >> y;
    Q.push({x, y});
    dis[x][y] = 0;
  }
  int mx = 0;
  pair <int, int> ans(1, 1);
  while (not Q.empty()) {
    pair <int, int> u = Q.front();
    Q.pop();
    int x = u.first;
    int y = u.second;
    for (int d = 0; d < 4; d++) {
      int nx = x + dx[d];
      int ny = y + dy[d];
      if (not (1 <= min(nx, ny) and nx <= n and ny <= m)) continue;
      if (dis[nx][ny] > dis[x][y] + 1) {
        dis[nx][ny] = dis[x][y] + 1;
        Q.push({nx, ny});
        if (dis[nx][ny] > mx) {
          mx = dis[nx][ny];
          ans = {nx, ny};
        }
      }
    }
  }
  cout << ans.first << ' ' << ans.second << endl;
  return (0);
}
