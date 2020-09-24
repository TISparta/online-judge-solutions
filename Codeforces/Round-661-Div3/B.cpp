// Greedy
// 2
// 05-08-2020

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
    int n;
    cin >> n;
    vi a(n);
    for (int& x: a) cin >> x;
    vi b(n);
    for (int& x: b) cin >> x;
    int x = *min_element(all(a));
    int y = *min_element(all(b));
    ll ans = 0;
    for (int i = 0; i < n; i++) {
      ll p = a[i] - x;
      ll q = b[i] - y;
      ll r = min(p, q);
      ans += r;
      p -= r;
      q -= r;
      ans += p;
      ans += q;
    }
    cout << ans << '\n';
  }
  return (0);
}
