// Tags: DP, Segment Tree
// Difficulty: 6.6
// Priority: 1
// Date: 20-05-2021

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
    int mn = 0;
    int add = 0;
  };
  vector <State> st;
  State NIL{INT_MAX, 0};

  STree (int l, int r): from(l), to(r) {
    st.resize(4 * r);
  }

  State merge (State lu, State ru) {
    return State{min(lu.mn, ru.mn), 0};
  }

  void push (int u, int l, int r) {
    if (st[u].add == 0) return;
    st[u].mn += st[u].add;
    if (l != r) {
      st[2 * u].add += st[u].add;
      st[2 * u + 1].add += st[u].add;
    }
    st[u].add = 0;
  }

  void update (int L, int R, int val, int u, int l, int r) {
    push(u, l, r);
    if (r < L or R < l) return;
    if (L <= l and r <= R) {
      st[u].add = val;
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
  int n, k;
  cin >> n >> k;
  vi a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vll dp(n);
  vi ff(n + 1, -1);
  vi ss(n + 1, -1);
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    if (ff[a[i]] == -1) {
      ff[a[i]] = ss[a[i]] = i;
    } else {
      sum -= (ss[a[i]] - ff[a[i]]);
      ss[a[i]] = i;
      sum += (ss[a[i]] - ff[a[i]]);
    }
    dp[i] = sum;
  }
  for (int it = 1; it < k; it++) {
    vll new_dp(n);
    vi last(n + 1, -1);
    int st = it - 1;
    STree tree(0, n);
    for (int i = it; i < n; i++) {
      tree.update(i - 1, i - 1, dp[i - 1]);
      if (last[a[i]] == -1) {
        last[a[i]] = i;
      } else {
        int d = i - last[a[i]];
        tree.update(st, last[a[i]] - 1, d);
        last[a[i]] = i;
      }
      new_dp[i] = tree.query(st, i - 1).mn;
    }
    dp = new_dp;
  }
  cout << dp.back() << '\n';
  return (0);
}
