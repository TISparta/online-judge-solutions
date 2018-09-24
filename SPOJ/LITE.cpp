/**
 * > Author : TISparta
 * > Date : 13-09-18
 * > Tags : Segment Tree, Lazy Propagation
 * > Difficulty : 4 / 10
 */

#include <bits/stdc++.h>

using namespace std;

struct STree {
  int l, r, ones = 0, lazy = 0;
  STree *left = 0, *right = 0;
  STree (int l, int r): l(l), r(r) {}
};

namespace ST {
  void build (STree*& root, int l, int r) {
    root = new STree(l, r);
    if (l == r) return;
    int m = (l + r) >> 1;
    build(root -> left, l, m);
    build(root -> right, m + 1, r);
  }
  void merge (STree*& root) {
    root -> ones = root -> left -> ones + root -> right -> ones;
  }
  void propagate (STree*& root) {
    if (root -> l != root -> r) {
      root -> left -> lazy ^= 1;
      root -> right -> lazy ^= 1;  
    }
  }
  void push (STree*& root) {
    if (root -> lazy == 0) return;
    root -> ones = (root -> r - root -> l + 1) - root -> ones;
    propagate(root);
    root -> lazy = 0;
  }
  void update (STree*& root, const int l, const int r) {
    push(root);
    if (r < root -> l or root -> r < l) return;
    if (l <= root -> l and root -> r <= r) {
      root -> ones = (root -> r - root -> l + 1) - root -> ones;
      propagate(root);
      return;
    }
    update(root -> left, l, r);
    update(root -> right,l, r);
    merge(root);
  }
  int get (STree*& root, const int l, const int r) {
    push(root);
    if (r < root -> l or root -> r < l) return 0;
    if (l <= root -> l and root -> r <= r) return root -> ones;
    int ret1 = get(root -> left,l, r);
    int ret2 = get(root -> right, l, r);
    merge(root);
    return ret1 + ret2;
  }
};

int main () {
  int n, m;
  STree *tree;
  scanf("%d %d", &n, &m);
  ST::build(tree, 1, n);
  while (m--) {
    int type, l, r;
    scanf("%d %d %d", &type, &l, &r);
    if (type == 0) ST::update(tree, l, r);
    else printf("%d\n", ST::get(tree, l, r));
  }
  return (0);
}
