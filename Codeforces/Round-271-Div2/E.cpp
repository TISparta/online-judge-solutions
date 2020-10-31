// Segment Tree, DP
// 6
// 31-10-2020

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

const ll INF = 1e16;

struct STree {
  int from, to;
  struct State {
    ll dp_val;
    int pos;
  };
  vector <State> st;
  State NIL{-INF, -1};

  void build (int u, int l, int r, const vpll& arr) {
    if (l == r) {
      st[u] = State({-INF, int(arr[l].second)});
      return;
    }
    int m = (l + r) >> 1;
    int lu = u << 1;
    int ru = lu | 1;
    build(lu, l, m, arr);
    build(ru, m + 1, r, arr);
    st[u] = merge(st[lu], st[ru]);
  }

  STree (int l, int r, const vpll& arr): from(l), to(r) {
    st.resize(4 * r);
    build(1, l, r, arr);
  }

  State merge (State lu, State ru) {
    if (lu.dp_val >= ru.dp_val) return lu;
    return ru;
  }

  void push (int u, int l, int r) {
    return;
  }

  void update (int L, int R, int val, int u, int l, int r) {
    push(u, l, r);
    if (r < L or R < l) return;
    if (L <= l and r <= R) {
      st[u].dp_val = val;
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
  ll n, d;
  cin >> n >> d;
  vpll h(n + 2);
  h[0] = mp(-INF, 0);
  h[n + 1] = mp(INF, n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> h[i].first;
    h[i].second = i;
  }
  sort(all(h));
  STree tree(0, n + 1, h);
  vi pos(n + 2);
  for (int i = 0; i <= n + 1; i++) {
    pos[h[i].second] = i;
  }
  vll dp(n + 1, -INF);
  vi prev(n + 1, -1);
  tree.update(pos[1], pos[1], 1);
  for (int i = 2; i <= n; i++) {
    // hi - hj >= d
    // hi - d >= hj
    ll hi = h[pos[i]].first;
    int x = upper_bound(all(h), pll(hi - d, INF)) - begin(h) - 1;
    auto best_x = tree.query(0, x);
    // hj - hi >= d
    // hj >= d + hi
    int y = upper_bound(all(h), pll(hi + d - 1, INF)) - begin(h);
    auto best_y = tree.query(y, n + 1);
    auto best = tree.merge(best_x, best_y);
    best = tree.merge(best, STree::State({0, -1}));
    dp[i] = 1 + best.dp_val;
    prev[i] = best.pos;
    tree.update(pos[i], pos[i], dp[i]);
  }
  auto cur = max_element(all(dp)) - begin(dp);
  cout << dp[cur] << '\n';
  vi ans = {int(cur)};
  while (prev[cur] != -1) {
    cur = prev[cur];
    ans.pb(cur);
  }
  reverse(all(ans));
  for (int i = 0; i < sz(ans); i++) cout << ans[i] << " \n"[i == sz(ans) - 1];
  return (0);
}
