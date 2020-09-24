// Greedy
// 4
// 11-09-2020

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
  int n, m;
  cin >> n >> m;
  vi a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  set <int> b;
  for (int i = 0; i < m; i++) {
    int bi;
    cin >> bi;
    b.insert(bi);
  }
  auto get = [&] (int x) {
    int ret = 0;
    for (int d = 2; d * d <= x; d++) {
      if (x % d) continue;
      int cost = b.count(d) ? -1 : 1;
      while (x % d == 0) {
        x /= d;
        ret += cost;
      }
    }
    if (x != 1) {
      if (b.count(x)) ret -= 1;
      else ret += 1;
    }
    return ret;
  };
  for (int r = n - 1; r >= 0; r--) {
    int g = a[0];
    for (int l = 1; l <= r; l++) g = __gcd(g, a[l]);
    if (get(g) < 0) for (int l = 0; l <= r; l++) a[l] /= g;
  }
  ll ans = 0;
  for (int ai: a) ans += get(ai);
  cout << ans << '\n';
  return (0);
}
