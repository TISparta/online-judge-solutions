/**
 * > Author : TISparta
 * > Date : 10-09-18
 * > Tags : Segment Tree
 * > Difficulty : 5 / 10
 */

#include <bits/stdc++.h>

#define all(X) begin(X), end(X)

using namespace std;

const int MAX_N = 2e5, MAX_Q = 2e5;

vector <int> values;

struct STree {
  int cnt = 0;
  STree *left = 0, *right = 0;
  STree () {}
  ~STree () {
    delete left;
    delete right;
  }
};

int n, q, arr[MAX_N + 10], id[MAX_N + 10], a[MAX_N + 10];
STree* tree[MAX_N + MAX_Q + 10];

namespace ST {
  inline void merge (STree*& root) {
    root -> cnt = (root -> left ? root -> left -> cnt : 0) + (root -> right ? root -> right -> cnt : 0);
  }
  void update (STree*& root, const int pos, const int var, int l = 0, int r = n - 1) {
    if (not root) root = new STree();
    if (l == r) {
      root -> cnt += var;
      return;
    }
    int m = (l + r) >> 1;
    if (pos <= m) update(root -> left, pos, var, l, m);
    else update(root -> right, pos, var, m + 1, r);
    merge(root);
  }
  int get (STree*& root, const int from, const int to, int l = 0, int r = n - 1) {
    if (not root) return 0;
    if (to < l or r < from) return 0;
    if (from <= l and r <= to) return root -> cnt;
    int m = (l + r) >> 1;
    return get(root -> left, from, to, l, m) + get(root -> right, from, to, m + 1, r);
  }
};

void read () {
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; i++) scanf("%d", arr + i);
  for (int i = 0; i < q; i++) scanf("%d %d", id + i, a + i);
}

void compress () {
  values = vector <int> (arr, arr + n);
  values.insert(end(values), a, a + q);
  sort(all(values));
  values.erase(unique(all(values)), end(values));
  for (int i = 0; i < n; i++) arr[i] = lower_bound(all(values), arr[i]) - begin(values);
  for (int i = 0; i < q; i++) a[i] = lower_bound(all(values), a[i]) - begin(values);
}

int main () {
  read();
  compress();
  for (int i = 0; i < n; i++) ST::update(tree[arr[i]], i, 1);
  for (int i = 0; i < q; i++) {
    printf("%d\n", ST::get(tree[a[i]], 0, id[i] - 1));
    ST::update(tree[arr[id[i]]], id[i], -1);
    arr[id[i]] = a[i];
    ST::update(tree[arr[id[i]]], id[i], 1);
  }
  return (0);
}
