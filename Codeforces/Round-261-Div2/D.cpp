// BIT
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

template <typename T = int>
struct BIT {
  vector <T> ft;
  BIT (int n): ft(n + 2, 0) {}
  void update (int pos, T val) {
    while (pos < sz(ft)) {
      ft[pos] += val;
      pos += pos & -pos;
    }
  }
  void update (int l, int r, T val) {
    if (l > r) return;
    update(l, val);
    update(r + 1, -val);
  }
  T sum (int pos) {
    T ret = 0;
    while (pos) {
      ret += ft[pos];
      pos -= pos & -pos;
    }
    return ret;
  }
  T sum (int l, int r) {
    if (l > r) return 0;
    return sum(r) - sum(l - 1);
  }
};

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  vi a(n);
  vi values = {0};
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    values.pb(a[i]);
  }
  sort(all(values));
  values.erase(unique(all(values)), end(values));
  for (auto& ai: a) {
    ai = lower_bound(all(values), ai) - begin(values);
  }
  vi frec(n + 1, 0);
  vi arr;
  BIT ft(n + 1);
  for (int i = n - 1; i >= 0; i--) {
    frec[a[i]] += 1;
    arr.pb(frec[a[i]]);
    ft.update(frec[a[i]], 1);
  }
  fill(all(frec), 0);
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ft.update(arr.back(), -1);
    arr.pop_back();
    frec[a[i]] += 1;
    int fi = frec[a[i]];
    ans += ft.sum(fi - 1);
  }
  cout << ans << '\n';
  return (0);
}
