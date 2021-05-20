// Tags: Brute Force
// Difficulty: 3.5
// Priority: 3
// Date: 20-05-2021

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
    int n;
    cin >> n;
    map <int, vi> f;
    for (int i = 1; i <= n; i++) {
      int ai;
      cin >> ai;
      f[ai].pb(i);
    }
    ll ans = 0;
    for (auto [key, arr]: f) {
      int m = sz(arr);
      vll racc(m);
      racc[m - 1] = n + 1 - arr[m - 1];
      for (int i = m - 2; i >= 0; i--) {
        racc[i] = n + 1 - arr[i];
        racc[i] += racc[i + 1];
      }
      for (int i = 0; i + 1 < m; i++) {
        ans += 1LL * arr[i] * racc[i + 1];
      }
    }
    cout << ans << '\n';
  }
  return (0);
}
