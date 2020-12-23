// Implementation
// 2
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
  ll n, m, t;
  cin >> n >> m >> t;
  vpll a(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i].first >> a[i].second;
  }
  ll cur = n;
  ll prev = 0;
  bool ok = true;
  for (auto [a, b]: a) {
    cur = cur - (a - prev);
    ok &= (cur > 0);
    cur = cur + (b - a);
    cur = min(cur, n);
    prev = b;
  }
  cur = cur - (t - prev);
  ok &= (cur > 0);
  if (ok) cout << "Yes\n";
  else cout << "No\n";
  return (0);
}
