/**
 * > Author : TISparta
 * > Date : 14-08-18
 * > Tags : Segment Tree, Lazy Propagation
 * > Difficulty : 5 / 10
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e5 + 10;

struct STree {
  int l, r, sum, lazy = 0;
  bool is_leaf = false;
  STree *left, *right;
  STree (int _l, int _r): l(_l), r(_r) {}
  ~STree () {
    delete left;
    delete right;
  }
};

int n, root, cnt, arr[MAX_N], start[MAX_N], finish[MAX_N];
vector <int> G[MAX_N];

inline void merge (STree*& root) {
  root -> sum = root -> left -> sum + root -> right -> sum;
}

void build (STree*& root, int l, int r) {
  root = new STree(l, r);
  if (l == r) {
    root -> sum = 1;
    root -> is_leaf = true;
    return;
  }
  int m = (l + r) >> 1;
  build(root -> left, l, m);
  build(root -> right, m + 1, r);
  merge(root);
}

void propagate (STree*& root) {
  if (root -> lazy == 1) root -> sum = root -> r - root -> l + 1;
  if (root -> lazy == 2) root -> sum = 0;
  if (not root -> is_leaf) {
    root -> left -> lazy = root -> lazy;
    root -> right -> lazy = root -> lazy;
  }
  root -> lazy = 0;
}

void push (STree*& root) {
  if (root -> lazy == 0) return;
  propagate(root);
}

void update (STree*& root, const int l, const int r, const int type) {
  push(root);
  if (r < root -> l or root -> r < l) return;
  if (l <= root -> l and root -> r <= r) {
    root -> lazy = type;
    propagate(root);
    return;
  }
  update(root -> left, l, r, type);
  update(root -> right, l, r, type);
  merge(root);
}

int get (STree*& root, const int l, const int r) {
  push(root);
  if (r < root -> l or root -> r < l) return 0;
  if (l <= root -> l and root -> r <= r) return root -> sum;
  int ret1 = get(root -> left, l, r);
  int ret2 = get(root -> right, l, r);
  merge(root);
  return ret1 + ret2;
}

void processQueries () {
  STree *tree;
  build(tree, 1, cnt);
  int q;
  scanf("%d", &q);
  while (q--) {
    int type, u;
    scanf("%d %d", &type, &u);
    int l = start[u] + 1;
    int r = finish[u];
    if (type == 1) update(tree, l, r, 1);
    else if (type == 2) update(tree, l, r, 2);
    else printf("%d\n", get(tree, l, r));
  }
}

void dfs (int u, int p = -1) {
  start[u] = ++cnt;
  for (int v: G[u]) if (v != p) dfs(v, u);
  finish[u] = cnt;
}

void preprocess () {
  dfs(root);
}

void readTree () {
  scanf("%d", &n);
  for (int u = 1; u <= n; u++) {
    int p;
    scanf("%d", &p);
    if (p) G[p].push_back(u);
    else root = u;
  }
}

int main () {
  readTree();
  preprocess();
  processQueries();
  return (0);
}
