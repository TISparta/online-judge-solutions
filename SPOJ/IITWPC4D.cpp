/**
 * > Author : TISparta
 * > Date : 17-09-18
 * > Tags : Segment Tree, Lazy Propagation
 * > Difficulty : 5 / 10
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e5 + 10, INF = 1e9;

struct STree {
  int l, r, lazy = 0;
  pair <int, int> state;
  STree *left = 0, *right = 0;
  STree (int l, int r): l(l), r(r) {}
  ~STree () {
    delete left;
    delete right;
  }
};

int n, arr[MAX_N], ans[MAX_N];

pair <int, int> merge (const pair <int, int>& l, const pair <int, int>& r) {
  if (l.second < r.second) return l;
  if (l.second > r.second) return r;
  return r;
}

void merge (STree*& root) {
  pair <int, int> l = root -> left -> state;
  pair <int, int> r = root -> right -> state;
  root -> state = merge(l, r);
}

void build (STree*& root, int l, int r) {
  root = new STree(l, r);
  if (l == r) {
    root -> state = {l, arr[l]};
    return;
  }
  int m = (l + r) >> 1;
  build(root -> left, l, m);
  build(root -> right, m + 1, r);
  merge(root);
}

void push (STree*& root) {
  if (root -> lazy == 0) return;
  if (root -> left) {
    root -> left -> state.second -= root -> lazy;
    root -> right -> state.second -= root -> lazy;
    root -> left -> lazy += root -> lazy;
    root -> right -> lazy += root -> lazy;
  }
  root -> lazy = 0;
}

void update (STree*& root, const int l, const int r, const int inc) {
  push(root);
  if (r < root -> l or root -> r < l) return;
  if (l <= root -> l and root -> r <= r) {
    root -> state.second -= inc;
    root -> lazy = inc;
    push(root);
    return;   
  }
  update(root -> left, l, r, inc);
  update(root -> right, l, r, inc);
  merge(root);
}

pair <int, int> get (STree*& root, const int l, const int r) {
  push(root);
  if (r < root -> l or root -> r < l) return {n, INF};
  if (l <= root -> l and root -> r <= r) return root -> state;
  pair <int, int> ret1 = get(root -> left, l, r);
  pair <int, int> ret2 = get(root -> right, l, r);
  return merge(ret1, ret2);
}

void solve () {
  STree *tree;
  build(tree, 0, n - 1);
  int pib = n;
  for (int k = 0; k < n; k++) {
    int mn = get(tree, 0, n - 1).first;
    ans[mn] = pib--;
    update(tree, mn + 1, n - 1, 1);
    update(tree, mn, mn, -INF);
  }
  printf("%d", ans[0]);
  for (int i = 1; i < n; i++) printf(" %d", ans[i]);
  puts("");
}

bool valid () {
  for (int i = 0; i < n; i++) if (not (0 <= arr[i] and arr[i] <= i)) return false;
  return true;
}

void read () {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", arr + i);
}

int main () {
  int tc;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    printf("Test : %d\n", t);
    read();
    if (not valid()) puts("-1");
    else solve();
  }
  return (0);
}
