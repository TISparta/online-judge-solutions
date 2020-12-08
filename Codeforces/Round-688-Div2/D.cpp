// Probabilites, Greedy
// 4
// 04-12-2020

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
  vll val = {2};
  while (val.back() < (LLONG_MAX - 1) / 2) val.pb(2 * (1 + val.back()));
  while (tt--) {
    ll n;
    cin >> n;
    if (n & 1) {
      cout << -1 << '\n';
      continue;
    }
    vi a;
    for (int i = sz(val) - 1; i >= 0; i--) {
      while (val[i] <= n) {
        a.pb(1);
        for (int j = 0; j < i; j++) a.pb(0);
        n -= val[i];
      }
    }
    assert(sz(a) <= 2000);
    int m = sz(a);
    cout << m << '\n';
    for (int i = 0; i < m; i++) cout << a[i] << " \n"[i == m - 1];
  }
  return (0);
}
