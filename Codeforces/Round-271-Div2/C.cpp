// Brute Force, Implementation
// 5
// 30-10-2020

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
    int m = 4 * 4;
    vpii points(m);
    auto rotate90 = [&] (pii p, pii c) {
      pii v(p.first - c.first, p.second - c.second);
      // T(x, y) -> (-y, x)
      return pii(c.first - v.second, c.second + v.first);
    };
    map <pii, vpii> mp;
    for (int i = 0; i < 4; i++) {
      pii p, c;
      cin >> p.first >> p.second >> c.first >> c.second;
      for (int j = 0; j < 4; j++) {
        points[4 * i + j] = p;
        mp[p].emplace_back(j, i);
        p = rotate90(p, c);
      }
    }
    for (auto& pp: mp) sort(all(pp.second));
    const int INF = 1e9;
    int ans = INF;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < m; j++) {
        if (points[i] == points[j]) continue;
        for (int k = 0; k < m; k++) {
          if (points[i] == points[k] or points[j] == points[k]) continue;
          int ii = i >> 2;
          int jj = j >> 2;
          int kk = k >> 2;
          if (ii == jj or ii == kk or jj == kk) continue;
          pii a(points[j].first - points[i].first, points[j].second - points[i].second);
          pii b(points[k].first - points[i].first, points[k].second - points[i].second);
          if (a.first * b.first + a.second * b.second != 0) continue;
          if (a.first * a.first + a.second * a.second !=
              b.first * b.first + b.second * b.second) continue;
          pii p(points[i].first + a.first + b.first, points[i].second + a.second + b.second);
          int it = 0;
          for (auto [t, ll]: mp[p]) {
            it += 1;
            if (it == 5) break;
            if (ll == ii or ll == jj or ll == kk) continue;
            ans = min(ans, (i % 4) + (j % 4) + (k % 4) + t);
          }
        }
      }
    }
    if (ans == INF) ans = -1;
    cout << ans << '\n';
  }
  return (0);
}
