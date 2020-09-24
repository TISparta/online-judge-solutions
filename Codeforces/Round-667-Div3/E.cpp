// Brute Force, Binary Search
// 3
// 04-09-2020

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
  int tc;
  cin >> tc;
  while (tc--) {
    int n, k;
    cin >> n >> k;
    vi x(n);
    vi y(n);
    for (int& xi: x) cin >> xi;
    for (int& yi: y) cin >> yi;
    sort(all(x));
    int ans = 0;
    vector <tuple <int, int, int>> arr;
    auto f = [&] (int l, int r) {
      if (x.back() < l or r < x.front()) return 0;
      int i1 = lower_bound(all(x), l) - begin(x);
      int i2 = upper_bound(all(x), r) - begin(x) - 1;
      return i2 - i1 + 1;
    };
    for (int i = 0; i < n; i++) {
      int l = x[i];
      int r = x[i] + k;
      ans = max(ans, f(l, r) + f(r + 1, r + 1 + k));
      arr.emplace_back(l, r, f(l, r));
    }
    vi mx(sz(arr));
    mx[sz(arr) - 1] = get <2> (arr[sz(arr) - 1]);
    for (int i = sz(arr) - 2; i >= 0; i--) {
      mx[i] = max({mx[i + 1], get <2> (arr[i])});
    }
    int l = 0, r = 0;
    while (l < sz(arr)) {
      r = max(r, l + 1);
      while (r < sz(arr) and not(get <1> (arr[l]) < get <0> (arr[r]))) {
        r += 1;
      }
      if (r == sz(arr)) break;
      ans = max(ans, get <2> (arr[l]) + mx[r]);
      l += 1;
    }
    cout << ans << '\n';
  }
  return (0);
}
