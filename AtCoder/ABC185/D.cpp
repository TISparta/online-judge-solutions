// Greedy
// 3
// 13-12-2020

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
  vi a(m);
  for (auto& ai: a) cin >> ai;
  sort(all(a));
  vi b;
  int prev = 1;
  for (int ai: a) {
    int len = ai - prev;
    if (len > 0) b.pb(len);
    prev = ai + 1;
  }
  int len = n + 1 - prev;
  if (len > 0) b.pb(len);
  if (b.empty()) {
    cout << 0 << '\n';
    return (0);
  }
  int x = *min_element(all(b));
  ll ans = 0;
  for (auto bi: b) ans += (bi + x - 1) / x;
  cout << ans << '\n';
  return (0);
}
