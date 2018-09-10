/**
 * > Author : TISparta
 * > Date : 09-09-18
 * > Tags : BFS, DFS
 * > Difficulty : 5 / 10
 */

#include <bits/stdc++.h>

#define all(X) begin(X), end(X)

using namespace std;

const int MAX_N = 2e5, PRUNING = 1000;

int n, m, w[MAX_N + 5];
char line[MAX_N + 5];
vector <int> G[MAX_N + 5], IG[MAX_N + 5];
bool reachable[MAX_N + 5], vis[MAX_N + 5];
int s, f;
int path[MAX_N + 5];

void print (int u = f) {
  if (u != s) print(path[u]);
  printf("%c", w[u] + 'a');
}

void bfs () {
  queue <int> Q1, Q2;
  Q1.push(s);
  while (not Q1.empty()) {
    int d = INT_MAX;
    while (not Q1.empty()) {
      int p = Q1.front();
      Q1.pop();
      for (int v: G[p]) {
        if (vis[v]) continue;
        if (w[v] <= d) {
          if (w[v] < d) while (not Q2.empty()) vis[Q2.front()] = false, Q2.pop();
          vis[v] = true;
          path[v] = p;
          d = w[v];
          Q2.push(v);
        }
      }
    }
    if (vis[f]) break;
    while (not Q2.empty()) Q1.push(Q2.front()), vis[Q2.front()] = false, Q2.pop();
  }
}

void dfs (int u) {
  reachable[u] = true;
  for (const int& v: IG[u]) if (not reachable[v]) dfs(v);
}

inline bool cmp (const int& a, const int& b) {
  return w[a] < w[b];
}

void filterRow (int u) {
  if (not reachable[u]) {
    G[u] = {};
    return;
  }
  vector <int> add;
  bool ffound = false;
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    ffound |= v == f;
    if (not reachable[v]) continue;
    if (add.size() < PRUNING) add.push_back(v);
  }
  if (ffound) add.push_back(f);
  G[u] = add;
}

void filter () {
  for (int u = 1; u <= n; u++) filterRow(u);
}

void read () {
  scanf("%d %d\n", &n, &m);
  scanf("%s", 1 + line);
  for (int i = 1; line[i]; i++) w[i] = line[i] - 'a';
  for (int i = 0, u, v; i < m; i++) {
    scanf("%d %d", &u, &v);
    G[u].push_back(v);
    IG[v].push_back(u);
  }
  for (int u = 1; u <= n; u++) {
    sort(all(G[u]));
    G[u].erase(unique(all(G[u])), end(G[u]));
    sort(all(G[u]), cmp);
  }
  scanf("%d %d", &s, &f);
}

int main () {
  read();
  dfs(f);
  if (not reachable[s]) {
    puts("No way");
    return (0);
  }
  filter();
  bfs();
  print();
  puts("");
  return (0);
}
