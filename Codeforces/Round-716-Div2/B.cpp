// Combinatorics
// 1.5
// 19-04-2021

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
  const int mod = 1e9 + 7;
  while (tt--) {
    ll n, k;
    cin >> n >> k;
    ll ans = 1;
    for (int i = 0; i < k; i++) {
      ans = (ans * n) % mod;
    }
    cout << ans << '\n';
  }
  return (0);
}
