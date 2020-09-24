// Segment Tree
// 3
// 10-09-2020

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
  struct node { int l, r, val = 0, left = -1, right = -1; };
  vector <node> tree;
  function <void(int,int,int,int,int)> update = [&] (int u, int l, int r, int pos, int val) {
    if (not (l <= pos and pos <= r)) return;
    if (l == pos and pos == r) {
      tree[u].val = val;
      return;
    }
    int m = (l + r) >> 1;
    if (tree[u].left == -1) {
      tree[u].left = sz(tree);
      tree.pb({l, m, 0, -1, -1});
    }
    if (tree[u].right == -1) {
      tree[u].right = sz(tree);
      tree.pb({m + 1, r, 0, -1, -1});
    }
    update(tree[u].left, l, m, pos, val);
    update(tree[u].right, m + 1, r, pos, val);
    tree[u].val = max(tree[tree[u].left].val, tree[tree[u].right].val);
  };
  function <int(int,int,int,int,int)> get_max = [&] (int u, int l, int r, int L, int R) -> int {
    if (u == -1 or R < l or r < L) return 0;
    if (L <= l and r <= R) return tree[u].val;
    int m = (l + r) >> 1;
    return max(get_max(tree[u].left, l, m, L, R), get_max(tree[u].right, m + 1, r, L, R));
  };
  tree.pb({0, int(1e9), 0, -1, -1});
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int ai;
    cin >> ai;
    cout << get_max(0, 0, 1e9, 0, ai - 1) << " \n"[i == n];
    update(0, 0, 1e9, ai, i);
  }
  return (0);
}
