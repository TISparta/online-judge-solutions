// Sparse Table
// 4
// 19-10-2020

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
  const int LG = 18;
  vector <vi> st;
  
  inline int op(int x, int y) {
    return __gcd(x, y);
  }

  STable (int n, const vi& arr) {
    st = vector <vi> (n + 1, vi(LG));
    for (int i = 1; i <= n; i++) {
      st[i][0] = arr[i];
    }
    for (int bit = 1; bit < LG; bit++) {
      for (int i = 1; i + (1 << bit) <= n; i++) {
        int j = i + (1 << (bit - 1));
        st[i][bit] = op(st[i][bit - 1], st[j][bit - 1]);
      }
    }
  }

  int query (int l, int r) {
    if (l == r) return st[l][0];
    int x = 31 - __builtin_clz(r - l);
    int ll = r - (1 << x) + 1;
    return op(st[l][x], st[ll][x]);
  }

};

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  vi a(n + 1);
  map <int, vi> pos;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pos[a[i]].pb(i);
  }
  STable st(n, a);
  auto count_frec = [&] (int x, int l, int r) {
    return upper_bound(all(pos[x]), r) - lower_bound(all(pos[x]), l);
  };
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    int g = st.query(l, r);
    cout << r - l + 1 - count_frec(g, l, r) << endl;
  }
  return (0);
}
