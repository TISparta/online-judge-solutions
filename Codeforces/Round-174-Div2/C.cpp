// Tags: Segment Tree, Lazy Propagation
// Difficulty: 3.1
// Priority: 2
// Date: 30-04-2021

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
    ll sum = 0;
    ll lazy = 0;
  };
  vector <State> st;
  State NIL{0,0};

  STree (int l, int r): from(l), to(r) {
    st.resize(4 * r, NIL);
  }

  State merge (State lu, State ru) {
    return State{lu.sum + ru.sum, 0};
  }

  void push (int u, int l, int r) {
    if (st[u].lazy == 0) return;
    st[u].sum += st[u].lazy * (r - l + 1);
    if (l != r) {
      st[2 * u].lazy += st[u].lazy;
      st[2 * u + 1].lazy += st[u].lazy;
    }
    st[u].lazy = 0;
  }

  void update (int L, int R, int val, int u, int l, int r) {
    push(u, l, r);
    if (r < L or R < l) return;
    if (L <= l and r <= R) {
      st[u].lazy = val;
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
  int n;
  cin >> n;
  STree st(1, n + 10);
  int pos = 1;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      ll a, x;
      cin >> a >> x;
      st.update(1, a, x);
    }
    if (t == 2) {
      ll k;
      cin >> k;
      pos += 1;
      st.update(pos, pos, k);
    }
    if (t == 3) {
      ll ai = st.query(pos, pos).sum;
      st.update(pos, pos, -ai);
      pos -= 1;
    }
    ll sum = st.query(1, pos).sum;
    cout << fixed << setprecision(12) << 1.0 * sum / pos << '\n';
  }
  return (0);
}
