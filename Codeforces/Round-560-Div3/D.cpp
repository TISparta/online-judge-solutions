// Number Theory
// 3
// 03-12-2020

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
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vi d(n);
    auto is_prime = [&] (int x) {
      int cnt_div = 0;
      for (int d = 1; d * d <= x; d++) {
        if (x % d) continue;
        cnt_div += 1;
        if (d * d != x) cnt_div += 1;
      }
      return (cnt_div == 2);
    };
    vpii p;
    for (int i = 0; i < n; i++) {
      cin >> d[i];
      if (is_prime(d[i])) p.emplace_back(d[i], 1);
    }
    if (sz(p) == 0) {
      cout << -1 << '\n';
      continue;
    }
    for (int i = 0; i < sz(p); i++) {
      int pi = p[i].first;
      for (int a: d) {
        int x = a;
        int cnt = 0;
        while (x % pi == 0) {
          cnt += 1;
          x /= pi;
        }
        if (x == 1) p[i].second = max(p[i].second, cnt);
      }
    }
    if (sz(p) == 1) {
      vi exp;
      ll cur = 1;
      for (int i = 1; i <= p[0].second; i++) {
        cur *= p[0].first;
        exp.pb(cur);
      }
      cur *= p[0].first;
      sort(all(exp));
      sort(all(d));
      if (exp == d) {
        cout << cur << '\n';
      } else {
        cout << -1 << '\n';
      }
    } else {
      ll ans = 1;
      ll n_div = 1;
      for (auto [p, e]: p) {
        ll cur = 1;
        for (int i = 1; i <= e; i++) cur *= p;
        ans *= cur;
        n_div *= (e + 1);
      }
      if (n_div - 2 != n) {
        cout << -1 << '\n';
      } else {
        bool ok = true;
        for (int di: d) {
          ok &= (ans % di == 0 and di < ans);
        }
        if (ok) cout << ans << '\n';
        else cout << -1 << '\n';
      }
    }
  }
  return (0);
}
