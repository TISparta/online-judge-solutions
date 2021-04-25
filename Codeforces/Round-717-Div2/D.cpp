// Sparse table, Binary lifting, Number Theory
// 5.5
// 21-04-2021

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

struct STable {
  const int LG = 20;
  vector <vi> st;
  
  inline int op (int x, int y) {
    return min(x, y);
  }

  STable (int l, int r, const vi& arr) {
    st = vector <vi> (r + 1, vi(LG));
    for (int i = l; i <= r; i++) {
      st[i][0] = arr[i];
    }
    for (int bit = 1; bit < LG; bit++) {
      for (int i = l; i + (1 << bit) - 1 <= r; i++) {
        int j = i + (1 << (bit - 1));
        st[i][bit] = op(st[i][bit - 1], st[j][bit - 1]);
      }
    }
  }

  int query (int l, int r) {
    if (l == r) return st[l][0];
    int x = 31 - __builtin_clz(r - l);
    int l2 = r - (1 << x) + 1;
    return op(st[l][x], st[l2][x]);
  }

};


int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, q;
  cin >> n >> q;
  vi a(n);
  vi nxt(n, n);
  const int MAX_P = 1e5 + 10;
  vi last(MAX_P, -1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    int x = a[i];
    for (int p = 2; p * p <= x; p++) {
      if (x % p) continue;
      while (x % p == 0) {
        x /= p;
      }
      if (last[p] != -1) {
        nxt[last[p]] = min(nxt[last[p]], i);
      }
      last[p] = i;
    }
    if (x != 1) {
      if (last[x] != -1) {
        nxt[last[x]] = min(nxt[last[x]], i);
      }
      last[x] = i;
    }
  }
  STable st(0, n - 1, nxt);
  const int LG = 18;
  vector <vi> up(n, vi(LG));
  for (int i = 0; i < n; i++) {
    int lo = i, hi = n - 1;
    while (lo != hi) {
      int mid = (lo + hi + 1) >> 1;
      if (st.query(i, mid) > mid) lo = mid;
      else hi = mid - 1;
    }
    up[i][0] = lo + 1;
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int bit = 1; bit < LG; bit++) {
      int v = up[i][bit - 1];
      if (v == n) {
        up[i][bit] = n;
      } else {
        up[i][bit] = up[v][bit - 1];
      }
    }
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    l -= 1;
    r -= 1;
    int ans = 0;
    int z = l;
    for (int bit = LG - 1; bit >= 0; bit--) {
      if (up[z][bit] <= r) {
        ans |= (1 << bit);
        z = up[z][bit];
      }
    }
    cout << ans + 1 << '\n';
  }
  return (0);
}
