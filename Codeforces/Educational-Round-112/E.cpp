// Tags: Segment Tree, Lazy Propagation, Two Pointers
// Difficulty: 6.0
// Priority: 3
// Date: 31-07-2021

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

const int INF = 1e9;

struct STree {
  int from, to;
  struct State {
    int mn = 0;
    int lazy = 0;
  };
  vector <State> st;
  State NIL{INF, 0};

  STree (int l, int r): from(l), to(r) {
    st = vector <State> (4 * r, State{0, 0});
  }

  State merge (State lu, State ru) {
    return State{min(lu.mn, ru.mn), 0};
  }

  void push (int u, int l, int r) {
    if (st[u].lazy == 0) return;
    st[u].mn += st[u].lazy;
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
  int n, m;
  cin >> n >> m;
  vi l(n), r(n), w(n);
  vi val;
  for (int i = 0; i < n; i++) {
    cin >> l[i] >> r[i] >> w[i];
    val.pb(l[i]);
    val.pb(r[i]);
  }
  sort(all(val));
  val.erase(unique(all(val)), end(val));
  for (int i = 0; i < n; i++) {
    l[i] = lower_bound(all(val), l[i]) - begin(val);
    r[i] = lower_bound(all(val), r[i]) - begin(val);
    l[i] *= 2;
    r[i] *= 2;
  }
  vi p(n);
  iota(all(p), 0);
  sort(all(p), [&] (int i, int j) {
    return (w[i] < w[j]);
  });
  int k = max(*max_element(all(l)), *max_element(all(r)));
  STree st(0, k);
  int ptr_l = 0, ptr_r = -1;
  int ans = 1e9;
  while (ptr_l < n) {
    while (ptr_r + 1 < n and st.query(0, k).mn == 0) {
      ptr_r += 1;
      st.update(l[p[ptr_r]], r[p[ptr_r]], 1);
    }
    //cout << st.query(0, k).mn << endl;
    if (st.query(0, k).mn != 0) {
      //cout << ptr_l << ' ' << ptr_r << endl;
      ans = min(ans, w[p[ptr_r]] - w[p[ptr_l]]);
    }
    st.update(l[p[ptr_l]], r[p[ptr_l]], -1);
    ptr_l += 1;
  }
  cout << ans << '\n';
  return (0);
}
