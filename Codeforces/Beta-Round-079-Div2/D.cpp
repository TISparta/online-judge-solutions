// BIT
// 3
// 13-05-2020

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
  vpii arr(m);
  vi values;
  for (auto& pp: arr) {
    cin >> pp.first >> pp.second;
    values.pb(pp.first);
    values.pb(pp.second);
    values.pb(pp.first - 1);
    values.pb(pp.second - 1);
  }
  values.pb(-1);
  values.pb(0);
  values.pb(n - 1);
  values.pb(n);
  sort(all(values));
  values.erase(unique(all(values)), end(values));
  sort(all(arr), [&] (pii x, pii y) {
    if (x.second != y.second) {
      return x.second < y.second;
    }
    return x.first < y.first;
  });
  auto index = [&] (int x) {
    return 1 + lower_bound(all(values), x) - begin(values);
  };
  vi ft(sz(values) + 10, 0);
  const int mod = 1e9 + 7;
  auto update = [&] (int pos, int val) {
    while (pos < sz(ft)) {
      ft[pos] += val;
      if (ft[pos] >= mod) ft[pos] -= mod;
      pos += pos & -pos;
    }
  };
  auto get = [&] (int pos) {
    int ret = 0;
    while (pos) {
      ret += ft[pos];
      if (ret >= mod) ret -= mod;
      pos -= pos & -pos;
    }
    return ret;
  };
  update(index(0), 1);
  for (pii pp: arr) {
    int l = index(pp.first);
    int r = index(pp.second);
    int sum = get(r - 1) - get(l - 1);
    if (sum < 0) sum += mod;
    update(r, sum);
  }
  int ans = get(index(n)) - get(index(n - 1));
  if (ans < 0) ans += mod;
  cout << ans << '\n';
  return (0);
}
