// Math
// 3
// 04-09-2020

#include <bits/stdc++.h>
     
#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())
#define pb push_back
#define mp make_pair
     
using namespace std;
     
typedef unsigned long long ll;
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
    ll n, s;
    cin >> n >> s;
    auto get = [&] (ll m) {
      ll sum = 0;
      while (m) {
        sum += m % 10;
        m /= 10;
      }
      return sum;
    };
    ll x = n;
    ll y = n;
    ll p = 1;
    int cnt = 0;
    auto f = [&] (ll x, int y) {
      while (y--) {
        x /= 10;
      }
      return x % 10;
    };
    while (get(x) > s) {
      ll d = f(x, cnt);
      if (d != 0) {
        x -= p * d;
        x += p * 10;
      }
      p *= 10;
      cnt += 1;
    }
    cout << x - n << '\n';
  }
  return (0);
}
