/**
 * > Author : TISparta
 * > Date : 11-08-18
 * > Tags : Segment Tree
 * > Difficulty : 4 / 10
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 5e4 + 10, INF = INT_MAX;

struct State {
  int prefix, mx, suffix, sum;
  State () {};
  State (int _prefix, int _mx, int _suffix, int _sum):
    prefix(_prefix), mx(_mx), suffix(_suffix), sum(_sum) {}
  bool operator == (const State& other) {
    return prefix == other.prefix and mx == other.mx and
      suffix == other.suffix and sum == other.sum;
  }
} NIL(-INF, -INF, -INF, -INF);

struct STree {
  int l, r;
  State state;
  STree *left, *right;
  STree () {}
  STree (int _l, int _r): l(_l), r(_r) {}
};

int n, arr[MAX_N];

State merge (State s1, State s2) {
  if (s1 == NIL) return s2;
  if (s2 == NIL) return s1;
  int sum = s1.sum + s2.sum;
  int mx = max(s1.suffix + s2.prefix, max(s1.mx, s2.mx));
  int prefix = max(s1.prefix, s1.sum + s2.prefix);
  int suffix = max(s2.suffix, s1.suffix + s2.sum);
  return State(prefix, mx, suffix, sum);
}

void build (STree*& root, int l, int r) {
  root = new STree(l, r);
  if (l == r) {
    root -> state = State(arr[l], arr[l], arr[l], arr[l]);
    return;
  }
  int m = (l + r) >> 1;
  build(root -> left, l, m);
  build(root -> right, m + 1, r);
  root -> state = merge(root -> left -> state, root -> right -> state);
}

State get (STree*& root, const int l, const int r) {
  if (r < root -> l or root -> r < l) return NIL;
  if (l <= root -> l and root -> r <= r) return root -> state;
  return merge(get(root -> left, l, r), get(root -> right, l, r));
}

void update (STree*& root, const int pos, const int val) {
  if (root -> l == root -> r) {
    root -> state = State(val, val, val, val);
    return;
  }
  int m = (root -> l + root -> r) >> 1;
  if (pos <= m) update(root -> left, pos, val);
  else update(root -> right, pos, val);
  root -> state = merge(root -> left -> state, root -> right -> state);
}

void processQueries () {
  STree *tree = NULL;
  build(tree, 1, n);
  int q, type, l, r;
  scanf("%d", &q);
  while (q--) {
    scanf("%d %d %d", &type, &l, &r);
    if (type == 0) update(tree, l, r);
    else printf("%d\n", get(tree, l, r).mx);
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
