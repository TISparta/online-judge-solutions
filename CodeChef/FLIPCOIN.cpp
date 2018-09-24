/**
 * > Author : TISparta
 * > Date : 13-08-18
 * > Tags : Segment Tree, Lazy Propagation
 * > Difficulty : 4 / 10
 */

#include <bits/stdc++.h>

using namespace std;

struct STree {
  int l, r, sum = 0;
  bool flip = false, is_leaf = false;
  STree *left, *right;
  STree (int _l, int _r): l(_l), r(_r) {}
  ~STree () {
    delete left;
    delete right;
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
  root -> sum = root -> left -> sum + root -> right -> sum;
}

void propagate (STree*& root) {
  root -> sum = root -> r - root -> l + 1 - root -> sum;
  if (not root -> is_leaf) {
    root -> left -> flip = 1 - root -> left -> flip;
    root -> right -> flip = 1 - root -> right -> flip;
  }
  root -> flip = false;
}

void push (STree*& root) {
  if (not root -> flip) return;
  propagate(root);
}

void update (STree*& root, const int l, const int r) {
  push(root);
  if (r < root -> l or root -> r < l) return;
  if (l <= root -> l and root -> r <= r) {
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
  if (l <= root -> l and root -> r <= r) return root -> sum;
  int ret1 = get(root -> left, l, r);
  int ret2 = get(root -> right, l, r);
  merge(root);
  return ret1 + ret2;
}

int main () {
  int n, q;
  scanf("%d %d", &n, &q);
  STree *tree;
  build(tree, 0, n - 1);
  while (q--) {
    int type, l, r;
    scanf("%d %d %d", &type, &l, &r);
    if (type == 0) update(tree, l, r);
    else printf("%d\n", get(tree, l, r));
  }
  return (0);
}
