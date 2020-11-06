// Math
// 4
// 05-11-2020

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
  string s;
  cin >> s;
  if (sz(s) == 1) {
    cout << -1 << '\n';
    return (0);
  }
  const int INF = 1e9;
  auto go = [&] (string s, char d, char u) {
    int posu = -1;
    int n = sz(s);
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] == u) {
        posu = i;
        break;
      }
    }
    if (posu == -1) return INF;
    int ret = n - 1 - posu;
    s.erase(begin(s) + posu);
    int posd = -1;
    for (int i = n - 2; i >= 0; i--) {
      if (s[i] == d) {
        posd = i;
        break;
      }
    }
    if (posd == -1) return INF;
    ret += n - 2 - posd;
    s.erase(begin(s) + posd);
    if (sz(s) and s[0] == '0') {
      int pos = -1;
      for (int i = 0; i < sz(s); i++) {
        if (s[i] != '0') {
          pos = i;
          break;
        }
      }
      if (pos == -1) return INF;
      ret += pos;
    }
    return ret;
  };
  int ans = go(s, '0', '0');
  ans = min(ans, go(s, '2', '5'));
  ans = min(ans, go(s, '5', '0'));
  ans = min(ans, go(s, '7', '5'));
  if (ans == INF) ans = -1;
  cout << ans << '\n';
  return (0);
}
