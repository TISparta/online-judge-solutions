// Brute Force
// 1.0
// 30-04-2021

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
  ll p;
  cin >> p;
  int ans = 0;
  for (int x = 1; x < p; x++) {
    ll xx = x;
    bool ok = true;
    for (int t = 1; t <= p - 2; t++) {
      ll val = xx - 1;
      if (val < 0) val += p;
      if (val == 0) ok = false;
      xx = (xx * x) % p;
    }
    ll val = xx - 1;
    if (val < 0) val += p;
    if (ok and val == 0) ans += 1;
  }
  cout << ans << '\n';
  return (0);
}
