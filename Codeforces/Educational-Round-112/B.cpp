// Tags: Brute Force, Implementation
// Difficulty: 2.5
// Priority: 1
// Date: 30-03-2021

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
    ll W, H;
    cin >> W >> H;
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll w, h;
    cin >> w >> h;
    ll ww = x2 - x1;
    ll hh = y2 - y1;
    const ll INF = 1e18;
    vll movex = {0, abs(w - x1), abs((W - w) - x2)};
    movex.pb(-movex[1]);
    movex.pb(-movex[2]);
    vll movey = {0, abs(h - y1), abs((H - h) - y2)};
    movey.pb(-movey[1]);
    movey.pb(-movey[2]);
    auto go = [&] (ll X1, ll Y1, ll X2, ll Y2) {
      if (not (0 <= X1 and X1 <= W)) return INF;
      if (not (0 <= X2 and X2 <= W)) return INF;
      if (not (0 <= Y1 and Y1 <= H)) return INF;
      if (not (0 <= Y2 and Y2 <= H)) return INF;
      ll ret = INF;
      for (auto mx: movex) {
        for (auto my: movey) {
          ll xx1 = x1 + mx;
          ll xx2 = x2 + mx;
          ll yy1 = y1 + my;
          ll yy2 = y2 + my;
          bool ok1 = (0 <= min(xx1, xx2) and max(xx1, xx2) <= W);
          bool ok2 = (0 <= min(yy1, yy2) and max(yy1, yy2) <= H);
          if (not ok1 or not ok2) continue;
          ll rx1 = max(xx1, X1);
          ll rx2 = min(xx2, X2);
          ll ry1 = max(yy1, Y1);
          ll ry2 = min(yy2, Y2);
          if (rx1 < rx2 and ry1 < ry2) continue;
          ret = min(ret, abs(mx) + abs(my));
        }
      }
      return ret;
    };
    ll ans = go(0, 0, w, h);
    ans = min(ans, go(0, H - h, w, H));
    ans = min(ans, go(W - w, H - h, W, H));
    ans = min(ans, go(W - w, 0, W, h));
    if (ans == INF) {
      cout << -1 << '\n';
    } else {
      cout << fixed << setprecision(12) << ans << '\n';
    }
  }
  return (0);
}
