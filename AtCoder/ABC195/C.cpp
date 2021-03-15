// Math
// 2
// 13-03-2021

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
  ll n;
  cin >> n;
  ll l = 1;
  ll r = 1;
  ll len = 1;
  ll ans = 0;
  while (l <= n) {
    r *= 10;
    ll z = min(r - 1, n);
    ll c = z - l + 1;
    ll add = (len - 1) / 3;
    ans += c * add;
    l = r;
    len += 1;
  }
  cout << ans << '\n';
  return (0);
}
