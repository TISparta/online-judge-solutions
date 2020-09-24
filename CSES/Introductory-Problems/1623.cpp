// Brute Force
// 2
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
  int n;
  cin >> n;
  vll a(n);
  for (auto& ai: a) cin >> ai;
  ll ans = LLONG_MAX;
  for (int mask = 1; mask < (1 << n); mask++) {
    ll sum1 = 0;
    ll sum2 = 0;
    for (int bit = 0; bit < n; bit++) {
      if ((mask >> bit) & 1) sum1 += a[bit];
      else sum2 += a[bit];
    }
    ans = min(ans, abs(sum1 - sum2));
  }
  cout << ans << '\n';
  return (0);
}
