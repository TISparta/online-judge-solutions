// Math
// 4
// 03-09-2020

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
  vll ans = {0};
  for (ll k = 2; k <= n; k++) {
    ll p = (k - 1) * (k - 1);
    ll add = 2 * (k - 5) * (p - 4) + 5 * (p - 2) + 4 * (p - 3) + (2 * k - 1) * (2 * k - 2) / 2 - 2;
    ans.pb(ans.back() + add);
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << '\n';
  }
  return (0);
}
