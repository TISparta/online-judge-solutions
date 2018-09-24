/**
 * > Author : TISparta
 * > Date : 13-08-18
 * > Tags : Segment Tree
 * > Difficulty : 4 / 10
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e5 + 10;

struct STree {
  int l, r;
  int odd, even;
  STree *left, *right;
  STree (int _l, int _r): l(_l), r(_r) {}
  ~STree () {
    delete left;
    delete right;
  }
};

int n, arr[MAX_N];

void merge (STree*& root) {
  root -> odd = root -> left -> odd + root -> right -> odd;
  root -> even = root -> left -> even + root -> right -> even;
}

void build (STree*& root, int l, int r) {
  root = new STree(l, r);
  if (l == r) {
    root -> odd = (arr[l] % 2 == 1);
    root -> even = (arr[l] % 2 == 0);
    return;
  }
  int m = (l + r) >> 1;
  build(root -> left, l, m);
  build(root -> right, m + 1, r);
  merge(root);
}

void update (STree*& root, const int pos, const int val) {
  if (pos == root -> l and root -> r == pos) {
    root -> odd = (val % 2 == 1);
    root -> even = (val % 2 == 0);
    return;
  }
  int m = (root -> l + root -> r) >> 1;
  if (pos <= m) update(root -> left, pos, val);
  else update(root -> right, pos, val);
  merge(root);
}

int get (STree*& root, const int l, const int r, const int type) {
  if (r < root -> l or root -> r < l) return 0;
  if (l <= root -> l and root -> r <= r) return (type == 1) ? root -> even : root -> odd;
  return get(root -> left, l, r, type) + get(root -> right, l, r, type);
}

void processQueries () {
  int q;
  STree *tree;
  build(tree, 1, n);
  scanf("%d", &q);
  while (q--) {
    int type, l, r;
    scanf("%d %d %d", &type, &l, &r);
    if (type == 0) update(tree, l, r);
    else if (type == 1) printf("%d\n", get(tree, l, r, 1));
    else printf("%d\n", get(tree, l, r, 2));
  }
}

void readArray () {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", arr + i);
}

int main () {
  readArray();
  processQueries();
  return (0);
}
