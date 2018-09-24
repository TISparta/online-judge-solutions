/**
 * > Author : TISparta
 * > Date : 13-08-18
 * > Tags : Segment Tree
 * > Difficulty : 5 / 10
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX_N = 1e5 + 10;

struct STree {
  int l, r;
  ll sum;
  STree *left, *right;
  STree (int _l, int _r): l(_l), r(_r) {}
  ~STree () {
    delete left;
    delete right;
  }
};

int tc, n;
ll arr[MAX_N];

inline void merge (STree*& root) {
  root -> sum = root -> left -> sum + root -> right -> sum;
}

void build (STree*& root, int l, int r) {
  root = new STree(l, r);
  if (l == r) {
    root -> sum = arr[l];
    return;
  }
  int m = (l + r) >> 1;
  build(root -> left, l, m);
  build(root -> right, m + 1, r);
  merge(root);
}

void propagate (STree*& root) {
  if (root -> sum == root -> r - root -> l + 1) return;
  if (root -> l == root -> r) {
    root -> sum = sqrt(root -> sum);
    return;
  }
  propagate(root -> left);
  propagate(root -> right);
  merge(root);
}

void update (STree*& root, const int l, const int r) {
  if (r < root -> l or root -> r < l) return;
  if (l <= root -> l and root -> r <= r) {
    propagate(root);
    return;
  }
  update(root -> left, l, r);
  update(root -> right, l, r);
  merge(root);
}

ll get (STree*& root, const int l, const int r) {
  if (r < root -> l or root -> r < l) return 0LL;
  if (l <= root -> l and root -> r <= r) return root -> sum;
  return get(root -> left, l, r) + get(root -> right, l, r);
}

void processQueries () {
  STree *tree;
  build(tree, 1, n); 
  int q;
  scanf("%d", &q);
  printf("Case #%d:\n", ++tc);
  while (q--) {
    int type, l, r;
    scanf("%d %d %d", &type, &l, &r);
    if (l > r) swap(l, r);
    if (type == 0) update(tree, l, r);
    else printf("%lld\n", get(tree, l, r));
  }
  puts("");
}

bool readArray () {
  if (scanf("%d", &n) != 1) return false;
  for (int i = 1; i <= n; i++) scanf("%lld", arr + i);
  return true;
}

int main () {
  while (readArray()) processQueries();
  return (0);
}
