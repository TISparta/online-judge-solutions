#include <bits/stdc++.h>

using namespace std;

int n;
bool first = true;
vector <pair <int, bool>> a, b;
set <int> V;
map <int, int> color, vis;
map <int, set <int>> G;

void print () {
  puts("YES");
  for (auto x: color) cout << x.first << ' ' << (char)x.second << endl;
}

bool dfs (int u, int c) {
  vis[u] = true;
  color[u] = c;
  bool ret = true;
  for (auto v: G[u]) {
    if (color.count(v) and color[v] != c) return false;
    if (not vis.count(v)) ret |= dfs(v, c);
  }
  return ret;
}

bool solve () {
  for (int i = 0; i < n; i++) {
    int u = a[i].first, v = b[i].first;
    if (a[i].second + b[i].second == 0) {
      if (a[i].first != b[i].first) return false;
    }
    else if (a[i].second and b[i].second) {
      if (u == v) continue;
      G[u].insert(v);
      G[v].insert(u);
    }
    else if (a[i].second) {
      if (color.count(u) and color[u] != v) return false;
      color[u] = v;
    }
    else {
      if (color.count(v) and color[v] != u) return false;
      color[v] = u;
    }
  }
  for (int u: V) 
    if (not vis.count(u) and color.count(u) and not dfs(u, color[u])) return false;
  return true;
}

void read (vector <pair <int, bool>>& x) {
  string line;
  for (int i = 0; i < n; i++) {
    getline(cin, line);
    if (isdigit(line[0])) {
      V.insert(stoi(line));
      x.push_back({stoi(line), true});
    }
    else x.push_back({line[0], false});
  }
}

void init () {
  first = false;
  a.clear();
  b.clear();
  V.clear();
  G.clear();
  vis.clear();
  color.clear();
}

int main () {
  while (scanf("%d\n", &n) == 1) {
    if (not first) puts("");
    init();
    read(a);
    read(b);
    if (not solve()) puts("NO");
    else print();
  }
  return (0);
}
