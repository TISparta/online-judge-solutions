// Tags: Implementation
// Difficulty: 1.0
// Priority: 5
// Date: 14-04-2021

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
    int ans = 0;
    for (int d = 1; d <= 9; d++) {
      ll num = d;
      for (int it = 0; it < 11; it++) {
        if (num <= n) ans += 1;
        num = num * 10 + d;
      }
    }
    cout << ans << '\n';
  }
  return (0);
}
