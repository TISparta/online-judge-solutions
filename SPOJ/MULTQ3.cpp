/**
 * > Author : TISparta
 * > Date : 14-08-18
 * > Tags : Segment Tree, Lazy Propagation
 * > Difficulty : 4 / 10
 */

#include <bits/stdc++.h>

using namespace std;

struct STree {
  int l, r;
  int sum[3];
  int lazy = 0;
  bool is_leaf = false;
  STree *left, *right;
  STree (int _l, int _r): l(_l), r(_r) {
    sum[0] = _r - _l + 1;
    sum[1] = sum[2] = 0;
  }
};

void build (STree*& root, int l, int r) {
  root = new STree(l, r);
  if (l == r) {
    root -> is_leaf = true;
    return;
  }
  int m = (l + r) >> 1;
  build(root -> left, l, m);
  build(root -> right, m + 1, r);
}

void merge (STree*& root) {
  for (int i = 0; i < 3; i++) {
    root -> sum[i] = root -> left -> sum[i] + root -> right -> sum[i];
  }
}

void propagate (STree*& root) {
  if (root -> lazy == 1) {
    int tmp = root -> sum[0];
    root -> sum[0] = root -> sum[2];
    root -> sum[2] = root -> sum[1];
    root -> sum[1] = tmp;
  }
  else {
    int tmp = root -> sum[0];
    root -> sum[0] = root -> sum[1];
    root -> sum[1] = root -> sum[2];
    root -> sum[2] = tmp;
  }
  if (not root -> is_leaf) {
    root -> left -> lazy += root -> lazy;
    root -> left -> lazy %= 3;
    root -> right -> lazy += root -> lazy;
    root -> right -> lazy %= 3;
  }
  root -> lazy = 0;
}

void push (STree*& root) {
  if (root -> lazy == 0) return;
  propagate(root);
}

void update (STree*& root, const int l, const int r) {
  push(root);
  if (r < root -> l or root -> r < l) return;
  if (l <= root -> l and root -> r <= r) {
    root -> lazy = 1;
    propagate(root);
    return;
  }
  update(root -> left, l, r);
  update(root -> right, l, r);
  merge(root);
}

int get (STree*& root, const int l, const int r) {
  push(root);
  if (r < root -> l or root -> r < l) return 0;
  if (l <= root -> l and root -> r <= r) return root -> sum[0];
  int ret1 = get(root -> left, l, r);
  int ret2 = get(root -> right, l, r);
  merge(root);
  return ret1 + ret2;
}

int main () {
  STree *tree;
  int n, q;
  scanf("%d %d", &n, &q);
  build(tree, 0, n - 1);
  while (q--) {
    int type, l, r;
    scanf("%d %d %d", &type, &l, &r);
    if (type == 0) update(tree, l, r);
    else printf("%d\n", get(tree, l, r));
  }
  return (0);
}
