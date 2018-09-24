/**
 * > Author : TISparta
 * > Date : 01-09-18
 * > Tags : Segment Tree, Lazy Propagation
 * > Difficulty : 4 / 10
 */

#include <bits/stdc++.h>

typedef long long ll;

const int MAX_N = 1e4;

using namespace std;

struct STree {
  int l, r, cnt = 0, lazy = 0;
  STree *left = 0, *right = 0;
  STree (int l, int r): l(l), r(r) {}
  ~STree () {
    delete left;
    delete right;
  }
};

int n, q, arr[MAX_N + 10];
vector <bool> isPrime;

namespace ST {
  void merge (STree*& root) {
    root -> cnt = root -> left -> cnt + root -> right -> cnt;
  }

  void build(STree*& root, int l, int r) {
    root = new STree(l, r);
    if (l == r) {
      root -> cnt = isPrime[arr[l]];
      return;
    }
    int m = (l + r) >> 1;
    build(root -> left, l, m);
    build(root -> right, m + 1, r);
    merge(root);
  }

  void push (STree*& root) {
    if (root -> lazy == 0) return;
    root -> cnt = (root -> r - root -> l + 1) * isPrime[root -> lazy];
    if (root -> left) {
      root -> left -> lazy = root -> lazy;
      root -> right -> lazy = root -> lazy;
    }
    root -> lazy = 0;
  }

  void update (STree*& root, const int l, const int r, const int v) {
    push(root);
    if (r < root -> l or root -> r < l) return;
    if (l <= root -> l and root -> r <= r) {
      root -> lazy = v;
      push(root);
      return;
    }
    update(root -> left, l, r, v);
    update(root -> right, l, r, v);
    merge(root);
  } 

  int get (STree*& root, const int l, const int r) {
    push(root);
    if (r < root -> l or root -> r < l) return 0;
    if (l <= root -> l and root -> r <= r) return root -> cnt;
    int ret1 = get(root -> left, l, r);
    int ret2 = get(root -> right, l, r);
    merge(root);
    return ret1 + ret2;
  }
};

namespace NT {
  void sieve (int n) {
    isPrime.resize(n, true);
    isPrime[0] = isPrime[1] = false;
    for (ll i = 2; i < n; i++) if (isPrime[i]) for (ll j = 1LL * i * i; j < n; j += i) isPrime[j] = false;
  }
};

void processQueries () {
  STree *tree = nullptr;
  ST::build(tree, 1, n);
  while (q--) {
    int type, l, r, v;
    scanf("%d %d %d", &type, &l, &r);
    if (type == 1) printf("%d\n", ST::get(tree, l, r));
    else scanf("%d", &v), ST::update(tree, l, r, v);
  }
}

void readArray () {
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%d", arr + i);
}

int main () {
  NT::sieve(1e6 + 10);
  int tc;
  scanf("%d", &tc);
  for (int t = 1; t <= tc; t++) {
    printf("Case %d:\n", t);
    readArray();
    processQueries();
  }
  return (0);
}
