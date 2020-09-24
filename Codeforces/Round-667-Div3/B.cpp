// Greedy
// 4
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
    ll a, b, x, y, n;
    cin >> a >> b >> x >> y >> n;
    auto f = [&] (ll a, ll b, ll x, ll y, ll n) {
      ll z1 = min(n, a - x);
      a -= z1;
      n -= z1;
      ll z2 = min(n, b - y);
      b -= z2;
      n -= z2;
      return a * b;
    };
    cout << min(f(a, b, x, y, n), f(b, a, y, x, n)) << '\n';
  }
  return (0);
}
