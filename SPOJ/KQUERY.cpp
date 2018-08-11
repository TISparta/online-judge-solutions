/**
 * > Author : TISparta
 * > Date : 08-08-18
 * > Tags : Segment Tree
 * > Difficulty : 4 / 10
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 3e4 + 10, MAX_Q = 2e5 + 10;

struct Query {
  int l, r, k, id;
  Query () {}
  void read (int _id) {
    scanf("%d %d %d", &l, &r, &k);
    l--, r--;
    id = _id;
  }
  bool operator < (const Query& other) const {
    if (k != other.k) return k < other.k;
    return r < other.r;
  }
}query[MAX_Q];

struct STree {
  int l, r;
  int sum = 0;
  STree *left, *right;
  STree () {}
  STree (int _l, int _r): l(_l), r(_r) {}
};

int n, q, ans[MAX_Q];
pair <int, int> arr[MAX_N];

inline void merge(STree*& root) {
  root -> sum = root -> left -> sum + root -> right -> sum;
}

void build (STree*& root, int l, int r) {
  if (r < l) return;
  root = new STree(l, r);
  if (l == r) {
    root -> sum = 1;
    return;
  }
  int m = (l + r) >> 1;
  build(root -> left, l, m);
  build(root -> right, m + 1, r);
  merge(root);
}

void update (STree*& root, const int pos) {
  if (root -> l == pos and pos == root -> r) {
    root -> sum = 0;
    return;
  }
  int m = (root -> l + root -> r) >> 1;
  if (pos <= m) update(root -> left, pos);
  else update(root -> right, pos);
  merge(root);
}

int get (STree*& root, const int l, const int r) {
  if (r < root -> l or root -> r < l) return 0;
  if (l <= root -> l and root -> r <= r) return root -> sum;
  return get(root -> left, l, r) + get(root -> right, l, r);
}

void print () {
  for (int i = 0; i < q; i++) printf("%d\n", ans[i]);
}

void solve () {
  STree* tree;
  sort(arr, arr + n);
  sort(query, query + q);
  build(tree, 0, n - 1);
  int pos = 0;
  for (int i = 0; i < q; i++) {
    while (pos < n and arr[pos].first <= query[i].k) {
      update(tree, arr[pos].second);
      pos++;
    }
    ans[query[i].id] = get(tree, query[i].l, query[i].r);
  }
}

void read () {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i].first);
    arr[i].second = i;
  }
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    query[i].read(i);
  }
}

int main () {
  read();
  solve();
  print();
  return (0);
}
