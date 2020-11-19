// Implementation
// 1
// 19-11-2020

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
  int n, m;
  cin >> n >> m;
  vi a(n);
  for (int& ai: a) cin >> ai;
  vi b(m);
  for (int& bi: b) cin >> bi;
  int ans = INT_MAX;
  for (int d = 1; d <= 9; d++) {
    if (find(all(a), d) != end(a) and
        find(all(b), d) != end(b)) ans = min(ans, d);
  }
  int x = *min_element(all(a));
  int y = *min_element(all(b));
  ans = min({ans, x * 10 + y, y * 10 + x});
  cout << ans << '\n';
  return (0);
}
