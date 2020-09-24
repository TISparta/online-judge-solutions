// Two Pointers
// 2
// 06-09-2020

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
  int n, m, k;
  cin >> n >> m >> k;
  vi a(n);
  for (int& ai: a) cin >> ai;
  vi b(m);
  for (int& bi: b) cin >> bi;
  sort(all(a));
  sort(all(b));
  int cur = 0;
  int ans = 0;
  for (int x: a) {
    while (cur < m and b[cur] < x - k) cur += 1;
    if (cur < m and b[cur] <= x + k) {
      ans += 1;
      cur += 1;
    }
  }
  cout << ans << '\n';
  return (0);
}
