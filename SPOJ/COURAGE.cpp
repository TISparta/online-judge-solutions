/**
 * > Author : TISparta
 * > Date : 03-09-18
 * > Tags : Segment Tree
 * > Difficulty : 4 / 10
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX_N = 1e5;

struct STree {
  int l, r;
  ll sum = 0, mn = INT_MAX;
  STree *left = 0, *right = 0;
  STree (int l, int r): l(l), r(r) {}
  ~STree () {
    delete left;
    delete right;
  }
};

int n, q, arr[MAX_N];

namespace ST {
  void setLeaf (STree*& root, const int val) {
    root -> sum = root -> mn = val;
  }
  void merge (STree*& root) {
    root -> sum = root -> left -> sum + root -> right -> sum;
    root -> mn = min(root -> left -> mn, root -> right -> mn);
  }
  void build (STree*& root, int l, int r) {
    root = new STree(l, r);
    if (l == r) {
      setLeaf(root, arr[l]);
      return;
    }
    int m = (l + r) >> 1;
    build(root -> left, l, m);
    build(root -> right, m + 1, r);
    merge(root);
  }
  void update (STree*& root, const int pos, const int val) {
    if (root -> l == pos and pos == root -> r) {
      setLeaf(root, root -> mn + val);
      return;
    }
    if (pos <= root -> left -> r) update(root -> left, pos, val);
    else update(root -> right, pos, val);
    merge(root);
  }
  pair <ll, int> get (STree*& root, const int l, const int r) {
    if (r < root -> l or root -> r < l) return {0, INT_MAX};
    if (l <= root -> l and root -> r <= r) return {root -> sum, root -> mn};
    pair <ll, int> ret1 = get(root -> left, l, r);
    pair <ll, int> ret2 = get(root -> right, l, r);
    return {ret1.first + ret2.first, min(ret1.second, ret2.second)};
  }
};

void processQueries () {
  char w[10];
  int x, y;
  STree *tree = nullptr;
  ST::build(tree, 0, n - 1);
  scanf("%d", &q);
  while (q--) {
    getchar();
    scanf("%s %d %d", w, &x, &y);
    if (w[0] == 'E') {
      ST::update(tree, y, -x);      
    }
    else if (w[0] == 'G') {
      ST::update(tree, y, x);
    }
    else {
      pair <ll, int> ans = ST::get(tree, x, y);
      printf("%lld\n", ans.first - ans.second);
    }
  }
}

void readArray () {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", arr + i);
}

int main () {
  readArray();
  processQueries();
  return (0);
}
