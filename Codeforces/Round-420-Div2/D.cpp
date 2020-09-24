// Dijkstra
// 5
// 29-12-2018

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e4 + 10, INF = 1e9;
typedef pair <int, int> pii;

int n, m, k, dis[MAX_N];
bool visR[MAX_N], visC[MAX_N];
vector <pair <int, int>> arr;
vector <int> row[MAX_N], col[MAX_N];
map <pair <int, int>, int> mp;
vector <int> dr = {1, -1, 0, 0};
vector <int> dc = {0, 0, 1, -1};
set <pair <int, pii>> Q;

void turnOn (const vector <int>& lin, int d) {
  for (int id: lin) {
    if (dis[id] > d) {
      Q.erase({dis[id], arr[id]});
      dis[id] = d;
      Q.insert({dis[id], arr[id]});
    }
  }
}

int Dijkstra () {
  fill(dis, dis + MAX_N, INF);
  if (mp.count({n, m})) Q.insert({0, {n, m}});
  else {
    for (int r: {n - 1, n}) if (1 <= r) visR[r] = true, turnOn(row[r], 1);
    for (int c: {m - 1, m}) if (1 <= c) visC[m] = true, turnOn(col[c], 1);
  }
  while (not Q.empty()) {
    auto pp = *begin(Q);
    Q.erase(begin(Q));
    auto w = pp.first;
    auto u = pp.second;
    for (int d = 0; d < 4; d++) {
      pii v(u.first + dr[d], u.second + dc[d]);
      if (mp.count(v) and dis[mp[v]] > w) {
        Q.erase({dis[mp[v]], v});
        dis[mp[v]] = w;
        Q.insert({dis[mp[v]], v});
      }
    }
    for (int r = u.first - 2; r <= u.first + 2; r++) {
      if (1 <= r and r <= n and not visR[r]) {
        visR[r] = true;
        turnOn(row[r], w + 1);
      }
    }
    for (int c = u.second - 2; c <= u.second + 2; c++) {
      if (1 <= c and c <= m and not visC[c]) {
        visC[c] = true;
        turnOn(col[c], w + 1);
      }
    }
  }
  return dis[mp[{1, 1}]] == INF ? -1 : dis[mp[{1, 1}]];
}

int main () {
  cin >> n >> m >> k;
  for (int i = 0; i < k; i++) {
    int r, c;
    cin >> r >> c;
    arr.emplace_back(r, c);
    row[r].push_back(i);
    col[c].push_back(i);
    mp[{r, c}] = i;
  }
  cout << Dijkstra() << endl;
  return (0);
}
