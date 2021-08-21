// Tags: DFS
// Difficulty: 5.0
// Priority: 3
// Date: 31-03-2019

#include <bits/stdc++.h>

#define all(A) begin(A), end(A)
#define sz(A) int(A.size())

using namespace std;

typedef long long ll;

const int MAX_N = 2e5 + 10;

vector <int> G[MAX_N];
int ans[MAX_N];
int degree[MAX_N];
map <pair <int, int>, int> order;
pair <int, int> given[MAX_N];
bool vis[MAX_N];
bool marked[MAX_N];
vector <int> T[MAX_N];

void dfs (int u, bool in = true) {
  vis[u] = true;
  vector <int> go;
  for (int v: G[u]) {
    if (vis[v]) continue;
    go.push_back(v);
    int id = order[{min(u, v), max(u, v)}];
    if (in) {
      if (given[id].first == v and given[id].second == u) {
        ans[id] = 0;
      } else {
        ans[id] = 1;
      }
      T[v].push_back(u);
    } else {
      if (given[id].first == u and given[id].second == v) {
        ans[id] = 0;
      } else {
        ans[id] = 1;
      }
      T[u].push_back(v);
    }
  }
  for (int v: go) dfs(v, 1 - in);
}

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    order[{min(u, v), max(u, v)}] = i;
    G[u].push_back(v);
    G[v].push_back(u);
    given[i] = {u, v};
  }
  dfs(1, 1);
  for (int u = 1; u <= n; u++) {
    map <int, int> dis;
    queue <int> Q;
    dis[u] = 0;
    Q.push(u);
    while (not Q.empty()) {
      int p = Q.front();
      Q.pop();
      for (int v: T[p]) {
        dis[v] = dis[p] + 1;
        Q.push(v);
        if (dis[v] >= 2) {
          cout << "NO" << endl;
          return (0);
        }
      }
    }
  }
  cout << "YES" << endl;
  for (int i = 0; i < m; i++) cout << ans[i]; cout << endl;
  return (0);
}
