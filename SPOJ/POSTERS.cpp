/**
 * > Author : TISparta
 * > Date : 10-08-18
 * > Tags : Segment Tree, Lazy Propagation
 * > Difficulty : 5 / 10
 */

#include <bits/stdc++.h>

using namespace std;


struct STree {
  int l, r;
  int color = 0;
  STree *left = 0, *right = 0;
  STree () {}
  STree (int _l, int _r): l(_l), r(_r) {}
  ~STree () {
    delete left;
    delete right;
  }
};

void push (STree*& root) {
  int m = (root -> l + root -> r) >> 1;
  if (!root -> left) root -> left = new STree(root -> l, m);
  if (!root -> right) root -> right = new STree(m + 1, root -> r);
  if (root -> color) {
    root -> left -> color = root -> color;
    root -> right -> color = root -> color;
  }
  root -> color = 0;
}

void update (STree*& root, const int l, const int r, const int color) {
  if (r < root -> l or root -> r < l) return;
  if (l <= root -> l and root -> r <= r) {
    root -> color = color;
    return;
  }
  push(root);
  update(root -> left, l, r, color);
  update(root -> right, l, r, color);
}

void get (STree*& root, set <int>& cnt) {
  if (!root) return;
  if (root -> color) {
    cnt.insert(root -> color);
    return;
  }
  get (root -> left, cnt);
  get (root -> right, cnt);
}

void readAndSolve () {
  int n, l, r, mx = 0;
  set <int> cnt;
  scanf("%d", &n);
  STree* tree = new STree(0, 1e7);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &l, &r);
    update(tree, l - 1, r - 1, i);
  }
  get(tree, cnt);
  printf("%d\n", (int)cnt.size());
}

int main () {
  int tc;
  scanf("%d", &tc);
  while (tc--) readAndSolve();
  return (0);
}
