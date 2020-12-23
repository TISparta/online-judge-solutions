// Segment Tree
// 3
// 13-12-2020

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

struct STree {
  int from, to;
  struct State {
    int acc;
  };
  vector <State> st;
  State NIL{0};

  void build (int u, int l, int r, const vi& arr) {
    if (l == r) {
      st[u] = State{arr[l]};
      return;
    }
    int m = (l + r) >> 1;
    int lu = u << 1;
    int ru = lu | 1;
    build(lu, l, m, arr);
    build(ru, m + 1, r, arr);
    st[u] = merge(st[lu], st[ru]);
  }

  STree (int l, int r, const vi& arr): from(l), to(r) {
    st.resize(4 * r);
    build(1, l, r, arr);
  }

  State merge (State lu, State ru) {
    State ret{lu.acc ^ ru.acc};
    return ret;
  }

  void push (int u, int l, int r) {
    return;
  }

  void update (int L, int R, int val, int u, int l, int r) {
    push(u, l, r);
    if (r < L or R < l) return;
    if (L <= l and r <= R) {
      st[u].acc = val;
      push(u, l, r);
      return;
    }
    int m = (l + r) >> 1;
    int lu = u << 1;
    int ru = lu | 1;
    update(L, R, val, lu, l, m);
    update(L, R, val, ru, m + 1, r);
    st[u] = merge(st[lu], st[ru]);
  }

  void update (int L, int R, int val) { update(L, R, val, 1, from, to); }

  State query (int L, int R, int u, int l, int r) {
    push(u, l, r);
    if (r < L or R < l) return NIL;
    if (L <= l and r <= R) return st[u];
    int m = (l + r) >> 1;
    return merge(query(L, R, (u << 1), l, m), query(L, R, (u << 1) | 1, m + 1, r));
  }

  State query (int L, int R) { return query(L, R, 1, from, to); }

};


int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, q;
  cin >> n >> q;
  vi a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  STree tree(1, n, a);
  for (int i = 0; i < q; i++) {
    int t, x, y;
    cin >> t >> x >> y;
    if (t == 1) {
      tree.update(x, x, a[x] ^ y);
      a[x] = a[x] ^ y;
    } else {
      cout << tree.query(x, y).acc << '\n';
    }
  }
  return (0);
}
