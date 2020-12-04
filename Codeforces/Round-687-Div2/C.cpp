// Brute Force
// 2
// 29-11-2020

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
    ll n, p, k, x, y;
    string s;
    cin >> n >> p >> k >> s >> x >> y;
    vll need(n);
    for (int i = 0; i < k; i++) {
      need[n - 1 - i] = (s[n - 1 - i] == '0') * x;
    }
    for (int i = k; i < n; i++) {
      need[n - 1 - i] = need[n - 1 - i + k] + (s[n - 1 - i] == '0') * x;
    }
    ll ans = LLONG_MAX;
    for (int i = p - 1; i < n; i++) {
      ans = min(ans, need[i] + y * (i - p + 1));
    }
    cout << ans << '\n';
  }
  return (0);
}
