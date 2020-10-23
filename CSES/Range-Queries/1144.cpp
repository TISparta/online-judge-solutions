// Segment Tree
// 4
// 21-09-2020

#include <bits/stdc++.h>
     
#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())
#define pb push_back
#define mp make_pair
     
using namespace std;
     
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <pii> vpii;
typedef vector <pll> vpll;

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, q;
  cin >> n >> q;
  vi a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  struct node { int l, r, val = 0, left = -1, right = -1; };
  vector <node> tree;
  tree.pb(node({1, int(1e9), 0, -1, -1}));
  function <void(int,int,int)> update = [&] (int u, int pos, int val) -> void {
    if (not (tree[u].l <= pos and pos <= tree[u].r)) return;
    if (tree[u].l == pos and pos == tree[u].r) {
      tree[u].val += val;
      return;
    }
    int m = (tree[u].l + tree[u].r) / 2;
    if (pos <= m) {
      if (tree[u].left == -1) {
        tree[u].left = sz(tree);
        tree.pb(node({tree[u].l, m, 0, -1, -1}));
      }
      update(tree[u].left, pos, val);
    } else {
      if (tree[u].right == -1) {
        tree[u].right = sz(tree);
        tree.pb(node({m + 1, tree[u].r, 0, -1, -1}));
      }
      update(tree[u].right, pos, val);
    }
    tree[u].val = 0;
    if (tree[u].left != -1) tree[u].val += tree[tree[u].left].val;
    if (tree[u].right != -1) tree[u].val += tree[tree[u].right].val;
  };
  function <int(int,int,int)> query = [&] (int u, int L, int R) -> int {
    if (u == -1 or tree[u].r < L or R < tree[u].l) return 0;
    if (L <= tree[u].l and tree[u].r <= R) return tree[u].val;
    return query(tree[u].left, L, R) + query(tree[u].right, L, R);
  };
  for (int i = 1; i <= n; i++) {
    update(0, a[i], 1);
  }
  while (q--) {
    char t;
    int l, r;
    cin >> t >> l >> r;
    if (t == '!') {
      update(0, a[l], -1);
      a[l] = r;
      update(0, a[l], 1);
    } else {
      cout << query(0, l, r) << '\n';
    }
  }
  return (0);
}
