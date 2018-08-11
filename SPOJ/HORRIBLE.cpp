/**
 * > Author : TISparta
 * > Date : 10-08-18
 * > Tags : Segment Tree, Lazy Propagation
 * > Difficulty : 4 / 10
 */

#include <bits/stdc++.h>

using namespace std;

struct STree {
  int l, r, len;
  long long sum = 0, lazy = 0;
  STree *left = 0, *right = 0;
  STree () {}
  STree (int _l, int _r) {
    l = _l, r = _r, len = r - l + 1;
  }
  ~STree () {
    delete left;
    delete right;
  }
};

void push (STree*& root) {
  int m = (root -> l + root -> r) >> 1;
  if (!root -> left) root -> left = new STree(root -> l, m);
  if (!root -> right) root -> right = new STree(m + 1, root -> r);
  root -> sum += root -> lazy * root -> len;
  root -> left -> lazy += root -> lazy;
  root -> right -> lazy += root -> lazy;
  root -> lazy = 0;
}

void merge (STree*& root) {
  root -> sum = root -> left -> sum + root -> right -> sum;
  root -> sum += root -> left -> lazy * root -> left -> len;
  root -> sum += root -> right -> lazy * root -> right -> len;
}

void update (STree*& root, const int l, const int r, const int add) {
  if (r < root -> l or root -> r < l) return;
  if (l <= root -> l and root -> r <= r) {
    root -> lazy += add;
    return;
  }
  push(root);
  update(root -> left, l, r, add);
  update(root -> right, l, r, add);
  merge(root);
}

long long get (STree*& root, const int l, const int r) {
  if (r < root -> l or root -> r < l) return 0;
  push(root);
  if (l <= root -> l and root -> r <= r) return root -> sum;
  return get(root -> left, l, r) + get(root -> right, l, r);
}

void solveCase () {
  int n, c;
  scanf("%d %d", &n, &c);
  STree *tree = new STree(1, n);
  while (c--) {
    int type, p, q, v;
    scanf("%d", &type);
    if (type == 0) {
      scanf("%d %d %d", &p, &q, &v);
      update(tree, p, q, v);
    }
    else {
      scanf("%d %d", &p, &q);
      printf("%lld\n", get(tree, p, q));
    }
  }
}

int main () {
  int tc;
  scanf("%d", &tc);
  while (tc--) solveCase();
  return (0);
}
