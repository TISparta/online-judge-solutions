// Greedy, Binary Search
// 4
// 21-10-2020

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
  vi a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vpii b(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i].first >> b[i].second;
  }
  auto eval = [&] (int x) {
    vi last(n + 1, -1);
    for (auto [d, t]: b) {
      if (d <= x) {
        last[t] = max(last[t], d);
      }
    }
    vpii arr;
    int extra = 0;
    for (int i = 1; i <= n; i++) {
      if (last[i] == -1) {
        extra += 2 * a[i];
      } else {
        arr.emplace_back(last[i], a[i]);
      }
    }
    sort(all(arr));
    int cur = 0;
    int prev = 0;
    for (auto [d, ai]: arr) {
      cur += d - prev;
      int x = min(cur, ai);
      int y = ai - x;
      cur -= x;
      extra += 2 * y;
      prev = d;
    }
    cur += x - prev;
    return bool(extra <= cur);
  };
  int l = 1, r = 4e5 + 1;
  while (l != r) {
    int m = (l + r) >> 1;
    if (eval(m)) r = m;
    else l = m + 1;
  }
  cout << l << '\n';
  return (0);
}
