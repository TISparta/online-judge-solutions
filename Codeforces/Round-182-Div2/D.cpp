// Tags: Math
// Difficulty: 5.0
// Priority: 2
// Date: 02-08-2019

#include <bits/stdc++.h>

#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

ll findStart (ll l, ll L, ll pos) {
  ll p = (l + 1) / 2;
  ll q = l / 2;
  if (0 <= pos - p and pos + q <= L) return pos - p;
  if (pos - p < 0) return 0;
  if (pos + q > L) return L - l;
};

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  ll n, m, x, y, a, b;
  cin >> n >> m >> x >> y >> a >> b;
  ll g = __gcd(a, b);
  a /= g;
  b /= g;
  ll k = min(n / a, m / b);
  ll X = a * k;
  ll Y = b * k;
  ll sx = findStart(X, n, x);
  ll sy = findStart(Y, m, y);
  cout << sx << ' ' << sy << ' ' << sx + X << ' ' << sy + Y << '\n';
  return (0);
}
