// Tags: Segment Tree
// Difficulty: 4.0
// Priority: 3
// Date: 24-01-2019

#include <bits/stdc++.h>

using namespace std;

struct STree {
  int l,r, mn;
  int lazy = 0;
  STree *left = 0;
  STree *right = 0;
  STree () {}
  STree (int l, int r): l(l), r(r) {}
};

vector <int> arr;

void build (STree*& root, int l, int r) {
  root = new STree(l, r);
  if (l == r) {
    root -> mn = arr[l];
    return;
  }
  int m = (l + r) / 2;
  build(root -> left, l, m);
  build(root -> right, m + 1, r);
  root -> mn = min(root -> left -> mn, root -> right -> mn);
}

inline void push (STree*& root) {
  if (root -> lazy == 0) return;
  root -> mn += root -> lazy;
  if (root -> left) {
    root -> left -> lazy += root -> lazy;
    root -> right -> lazy += root -> lazy;
  }
  root -> lazy = 0;
}

void update (STree*& root, const int l, const int r, const int var) {
  push(root);
  if (r < root -> l or root -> r < l) return;
  if (l <= root -> l and root -> r <= r) {
    root -> lazy = var;
    push(root);
    return;
  }
  update(root -> left, l, r, var);
  update(root -> right, l, r, var);
  root -> mn = min(root -> left -> mn, root -> right -> mn);
}

int main () {
  int n, m;
  scanf("%d %d", &n, &m);
  arr.resize(n + 1);
  int mx = INT_MIN; 
  for (int i = 1; i <= n; i++) scanf("%d", &arr[i]), mx = max(mx, arr[i]);
  vector <pair <int, int>> seg(m + 1);
  for (int i = 1; i <= m; i++) scanf("%d %d", &seg[i].first, &seg[i].second);
  vector <int> applied;
  STree* tree;
  build(tree, 1, n);
  int ans = mx - tree -> mn;
  vector <bool> used(m + 1, false);
  for (int i = 1; i <= n; i++) {
    int mx = arr[i];
    vector <int> tmp;
    for (int k = 1; k <= m; k++) {
      int l = seg[k].first, r = seg[k].second;
      if (not (l <= i and i <= r)) {
        tmp.push_back(k);
        if (not used[k]) {
          update(tree, l, r, -1);
          used[k] = true;
        }
      }
      else if (used[k]) {
        update(tree, l, r, 1);
        used[k] = false;
      }
    }
    int mn = tree -> mn;
    if (mx - mn > ans) {
      ans = mx - mn;
      applied = tmp;
    }
  }
  printf("%d\n", ans);
  printf("%d\n", int(applied.size()));
  for (int elem: applied) printf("%d ", elem); puts("");
  return (0);
}
