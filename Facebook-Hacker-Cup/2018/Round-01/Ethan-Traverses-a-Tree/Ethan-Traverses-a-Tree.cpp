/**
 * > Author: TISparta
 * > Date: 21-07-18
 * > Tags: DSU
 * > Difficulty: 4 / 10
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX_V = 2e3 + 10, ROOT = 1;

int n, k, _left[MAX_V], _right[MAX_V], color[MAX_V];
vector <int> pre, post;

namespace DSU {
  int root[MAX_V];
  void build () {
    for (int u = 0; u < MAX_V; u++) root[u] = u;
  }
  int find (int u) {
    return root[u] == u ? u : root[u] = find(root[u]);
  }
  void join (int u, int v) {
    int x = find(u), y = find(v);
    root[x] = y;
  }
}

void printLabels () {
  for (int u = 1; u <= n; u++) cout << ' ' << color[u];
  cout << endl;
}

bool getLabels () {
  DSU::build();
  for (int i = 0; i < pre.size(); i++) DSU::join(pre[i], post[i]);
  int c = 1;
  bool ok = false;
  for (int u = 1; u <= n; u++) {
    int r = DSU::find(u);
    if (color[r] == 0) color[r] = c++;
    color[u] = color[r];
    if (c == k + 1) c = 1, ok = true;
  }
  if (not ok) return false;
  for (int i = 0; i < pre.size(); i++) if (color[pre[i]] != color[post[i]]) return false;
  return true;
}

void preOrder (int root) {
  if (root == 0) return;
  pre.push_back(root);
  preOrder(_left[root]);
  preOrder(_right[root]);
}

void postOrder (int root) {
  if (root == 0) return;
  postOrder(_left[root]);
  postOrder(_right[root]);
  post.push_back(root);
}

void readInput () {
  cin >> n >> k;
  for (int u = 1; u <= n; u++) {
    cin >> _left[u] >> _right[u];
  }
}

void clearCase () {
  memset(color, 0, sizeof color);
  pre.clear();
  post.clear();
}

int main () {
  int tc;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    clearCase();
    readInput();
    preOrder(ROOT);
    postOrder(ROOT);
    cout << "Case #" << t << ':';
    if (getLabels()) printLabels();
    else cout << " Impossible" << endl;
  }
  return (0);
}
