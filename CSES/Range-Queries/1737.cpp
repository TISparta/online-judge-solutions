// Persistent Segment Tree
// 5
// 23-10-2020

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

struct node {
  int lu, ru;
  ll sum;
} NIL{-1, -1, 0};

vector <node> st;
int cnt = 1;

int build (int l, int r, const vi& a) {
  int x = sz(st);
  st.pb({-1, -1, 0});
  if (l == r) {
    st[x].sum = a[l];
    return x;
  }
  int m = (l + r) >> 1;
  st[x].lu = build(l, m, a);
  st[x].ru = build(m + 1, r, a);
  st[x].sum = st[st[x].lu].sum + st[st[x].ru].sum;
  return x;
}

int update (int u, int pos, int val, int l, int r) {
  int x = sz(st);
  st.pb(st[u]);
  if (pos == l and pos == r) {
    st[x].sum = val;
    return x;
  }
  int m = (l + r) >> 1;
  if (pos <= m) {
    st[x].lu = update(st[x].lu, pos, val, l, m);
  } else {
    st[x].ru = update(st[x].ru, pos, val, m + 1, r);
  }
  st[x].sum = st[st[x].lu].sum + st[st[x].ru].sum;
  return x;
}

ll query (int u, int L, int R, int l, int r) {
  if (r < L or R < l) return 0LL;
  if (L <= l and r <= R) return st[u].sum;
  int m = (l + r) >> 1;
  return query(st[u].lu, L, R, l, m) + query(st[u].ru, L, R, m + 1, r);
}

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, q;
  cin >> n >> q;
  vi a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  build(1, n, a);
  vi array = {0};
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int k, a, x;
      cin >> k >> a >> x;
      array[k - 1] = update(array[k - 1], a, x, 1, n);
    } else if (type == 2) {
      int k, a, b;
      cin >> k >> a >> b;
      cout << query(array[k - 1], a, b, 1, n) << '\n';
    } else {
      int k;
      cin >> k;
      int x = sz(st);
      st.pb(st[array[k - 1]]);
      array.pb(x);
    }
  }
  return (0);
}
