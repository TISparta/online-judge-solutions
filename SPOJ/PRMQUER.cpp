/**
 * > Author : TISparta
 * > Date : 02-09-18
 * > Tags : Segment Tree, Lazy Propagation
 * > Difficulty : 5 / 10
 */

#include <bits/stdc++.h>

typedef long long ll;

const int MAX_N = 1e5;

using namespace std;

struct STree {
  int l, r, cnt, lazy = 0;
  STree *left = 0, *right = 0;
  STree (int l, int r): l(l), r(r) {}
  ~STree () {
    delete left;
    delete right;
  }
};

int n, q, arr[MAX_N + 10];

namespace NT {
  vector <bool> is_prime;
  void sieve (int n) {
    is_prime.resize(n, true);
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i < n; i++) if (is_prime[i]) for (ll j = i * i; j < n; j += i) is_prime[j] = false;
  }

  inline bool isPrime (const int num) {
    return num <= 1e7 and is_prime[num];
  }
};

namespace ST {
  void merge (STree*& root) {
    root -> cnt = root -> left -> cnt + root -> right -> cnt;
  }

  void build(STree*& root, int l, int r) {
    root = new STree(l, r);
    if (l == r) {
      root -> cnt = NT::isPrime(arr[l]);
      return;
    }
    int m = (l + r) >> 1;
    build(root -> left, l, m);
    build(root -> right, m + 1, r);
    merge(root);
  }

  void push (STree*& root) {
    if (root -> lazy == 0) return;
    root -> cnt = (root -> r - root -> l + 1) * NT::isPrime(root -> lazy);
    if (root -> left) root -> left -> lazy = root -> lazy;
    if (root -> right) root -> right -> lazy = root -> lazy;
    if (root -> l == root -> r) arr[root -> l] = root -> lazy;
    root -> lazy = 0;
  }

  void updatePoint (STree*& root, const int pos, const int v) {
    push(root);
    if (not (root -> l <= pos and pos <= root -> r)) return;
    if (root -> l == pos and root -> r == pos) {
      arr[pos] += v;
      root -> cnt = NT::isPrime(arr[pos]);
      return;
    }
    updatePoint(root -> left, pos, v);
    updatePoint(root -> right, pos, v);
    merge(root);
  }

  void updateRange (STree*& root, const int l, const int r, const int v) {
    push(root);
    if (r < root -> l or root -> r < l) return;
    if (l <= root -> l and root -> r <= r) {
      root -> lazy = v;
      push(root);
      return;
    }
    updateRange(root -> left, l, r, v);
    updateRange(root -> right, l, r, v);
    merge(root);
  } 

  int get (STree*& root, const int l, const int r) {
    push(root);
    if (r < root -> l or root -> r < l) return 0;
    if (l <= root -> l and root -> r <= r) return root -> cnt;
    int ret1 = get(root -> left, l, r);
    int ret2 = get(root -> right, l, r);
    return ret1 + ret2;
  }
};

void processQueries () {
  STree *tree = nullptr;
  ST::build(tree, 1, n);
  while (q--) {
    char type;
    int l, r, v;
    getchar();
    scanf("%c", &type);
    if (type == 'A') {
      scanf("%d %d", &v, &l);
      ST::updatePoint(tree, l, v);
    }
    else if (type == 'R') {
      scanf("%d %d %d", &v, &l, &r);
      ST::updateRange(tree, l, r, v);
    }
    else if (type == 'Q') {
      scanf("%d %d", &l, &r);
      printf("%d\n", ST::get(tree, l, r));
    }
  }
}

void readArray () {
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%d", arr + i);
}

int main () {
  NT::sieve(1e7 + 10);
  readArray();
  processQueries();
  return (0);
}
