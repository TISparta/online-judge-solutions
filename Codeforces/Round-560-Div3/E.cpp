// Greedy
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
  int n;
  cin >> n;
  vll a(n);
  for (auto& ai: a) cin >> ai;
  vll b(n);
  for (auto& bi: b) cin >> bi;
  for (int i = 0; i < n; i++) {
    int left = i + 1;
    int right = n - i;
    ll cnt = 1LL * left * right;
    a[i] *= cnt;
  }
  sort(all(a));
  sort(rall(b));
  int ans = 0;
  const int mod = 998244353;
  for (int i = 0; i < n; i++) {
    a[i] %= mod;
    int add = (1LL * a[i] * b[i]) % mod;
    ans += add;
    if (ans >= mod) ans -= mod;
  }
  cout << ans << '\n';
  return (0);
}
