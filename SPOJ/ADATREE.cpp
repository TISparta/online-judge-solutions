/**
 * > Author : TISparta
 * > Date : 10-09-18
 * > Tags : Segment Tree
 * > Difficulty : 5 / 10
 */

#include <bits/stdc++.h>

#define all(A) begin(A), end(A)

using namespace std;

const int MAX_N = 3e5;

struct STree {
  int l, r;
  vector <int> a;
  STree *left, *right;
  STree (int l, int r): l(l), r(r) {}
  ~STree () {
    delete left;
    delete right;
  }
};

int arr[MAX_N + 10];

namespace ST {
  void build (STree*& root, int l, int r) {
    root = new STree(l, r);
    if (l == r) {
      root -> a = {arr[l]};
      return;
    }
    int m = (l + r) >> 1;
    build(root -> left, l, m);
    build(root -> right, m + 1, r);
    merge(all(root -> left -> a), all(root -> right -> a), back_inserter(root -> a));
  }
  int get (const vector <int>& a, const int h) {
    if (a.front() > h) return 0;
    if (a.back() <= h) return a.back();
    int pos = lower_bound(all(a), h) - begin(a);
    return a[pos] <= h ? a[pos] : a[pos - 1]; 
  }
  int get (STree*& root, const int l, const int r, const int h) {
    if (r < root -> l or root -> r < l) return 0;
    if (l <= root -> l and root -> r <= r) return get(root -> a, h);
    return max(get(root -> left, l, r, h), get(root -> right, l, r, h));
  }
};

int main () {
  int n, q;
  STree *tree;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; i++) scanf("%d", arr + i);
  ST::build(tree, 0, n - 1);
  while (q--) {
    int l, r, h;
    scanf("%d %d %d", &l, &r, &h);
    printf("%d\n", ST::get(tree, l, r, h));
  }
  return (0);
}
