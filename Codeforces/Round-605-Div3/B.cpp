// Constructive Algorithms
// 2
// 13-10-2020

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
    string s;
    cin >> s;
    int l = count(all(s), 'L');
    int r = count(all(s), 'R');
    int u = count(all(s), 'U');
    int d = count(all(s), 'D');
    int x = min(l, r);
    l = x;
    r = x;
    int y = min(u, d);
    u = y;
    d = y;
    if (l == 0) {
      u = min(u, 1);
      d = min(d, 1);
    }
    if (u == 0) {
      l = min(l, 1);
      r = min(r, 1);
    }
    string ans = string(r, 'R') + string(u, 'U') + string(l, 'L') + string(d, 'D');
    cout << sz(ans) << '\n';
    cout << ans << '\n';
  }
  return (0);
}
