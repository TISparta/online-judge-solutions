// Tags: Brute Force
// Difficulty: 2.5
// Priority: 1
// DAte: 29-07-2021

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
    ll n, k;
    cin >> n >> k;
    vll a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    ll ans = 1 * 2 - k * (a[1] | a[2]);
    for (int i = 1; i <= n; i++) {
      for (int x = 1; x <= 200 and i + x <= n; x += 1) {
        int j = i + x;
        ans = max(ans, 1LL * i * j - k * (a[i] | a[j]));
      }
    }
    cout << ans << '\n';
  }
  return (0);
}
