// Brute Force
// 2
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
    int n, x, y;
    cin >> n >> x >> y;
    pair <int, vi> ans(INT_MAX, {});
    for (int p1 = 0; p1 < n; p1++) {
      for (int p2 = p1 + 1; p2 < n; p2++) {
        if ((y - x) % (p2 - p1)) continue;
        int d = (y - x) / (p2 - p1);
        vi a(n);
        a[p1] = x;
        for (int i = p1 - 1; i >= 0; i--) a[i] = a[i + 1] - d;
        for (int i = p1 + 1; i < n; i++) a[i] = a[i - 1] + d;
        if (a.front() < 1) continue;
        ans = min(ans, mp(a.back(), a));
      }
    }
    for (int i = 0; i < n; i++) {
      cout << ans.second[i] << " \n"[i == n - 1];
    }
  }
  return (0);
}
