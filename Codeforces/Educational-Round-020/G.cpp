// Segment Tree, Lazy Propagation
// 6
// 07-01-2019

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e5 + 10;

struct STree {
  int l, r;
  int mn;
  int lazy = 0;
  STree *left = 0;
  STree *right = 0;
  STree () {}
  STree (int l, int r): l(l), r(r) {} 
};

STree* tree;

int n, b[MAX_N];

void build (STree*& root, int l, int r) {
  root = new STree(l, r);
  if (l == r) {
    root -> mn = b[l];
    return;
  }
  int m = (l + r) >> 1;
  build(root -> left, l, m);
  build(root -> right, m + 1, r);
  root -> mn = min(root -> left -> mn, root -> right -> mn);
}

int get (STree*& root, int l, int r) {
  if (r < root -> l or root -> r < l) return INT_MAX;
  if (l <= root -> l and root -> r <= r) return root -> mn;
  return min(get(root -> right, l, r), get(root -> left, l, r));
}

int ask (int x, int y) {
  if (y - x >= n) return tree -> mn;
  x--, y--;
  x %= n, y %= n;
  x++, y++;
  if (x <= y) return get(tree, x, y);
  return min(get(tree, 1, y), get(tree, x, n));
}

inline void push (STree*& root) {
  if (root -> lazy == 0) return;
  root -> mn = root -> lazy;
  if (root -> left) {
    root -> left -> lazy = root -> right -> lazy = root -> lazy;
    root -> lazy = 0;
  }
}

inline void buildChildren (STree*& root) {
  int l = root -> l, r = root -> r, m = (l + r) >> 1;
  root -> left = new STree(l, m);
  root -> left -> mn = ask(l, m);
  root -> right = new STree(m + 1, r);
  root -> right -> mn = ask(m + 1, r);
  push(root);
}

void update (STree*& root, const int l, const int r, const int x) {
  push(root);
  if (r < root -> l or root -> r < l) return;
  if (l <= root -> l and root -> r <= r) {
    root -> lazy = x;
    push(root);
    return;
  }
  if (not root -> left) buildChildren(root);
  update(root -> left, l, r, x);
  update(root -> right, l, r, x);
  root -> mn = min(root -> left -> mn, root -> right -> mn);
}


int query (STree*& root, const int l, const int r) {
  push(root);
  if (r < root -> l or root -> r < l) return INT_MAX;
  if (l <= root -> l and root -> r <= r) return root -> mn;
  if (not root -> left) buildChildren(root);
  return min(query(root -> left, l, r), query(root -> right, l, r));
}

int main () {
  int k;
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> b[i];
  build(tree, 1, n);
  STree* DTree = new STree(1, n * k);
  DTree -> mn = get(tree, 1, n);
  int q;
  cin >> q;
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int l, r, x;
      cin >> l >> r >> x;
      update(DTree, l, r, x);
    }
    else {
      int l, r;
      cin >> l >> r;
      cout << query(DTree, l, r) << endl; 
    }
  }
  return (0);
}
