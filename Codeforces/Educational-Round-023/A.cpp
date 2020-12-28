// Math
// 2
// 27-12-2020

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
  int x1, y1, x2, y2;
  int x, y;
  cin >> x1 >> y1 >> x2 >> y2 >> x >> y;
  auto sign = [&] (int p) { return p > 0 ? 1 : -1; };
  while (abs(x1 - x2) >= 2 * x) x1 = x1 + sign(x2 - x1) * 2 * x;
  while (abs(y1 - y2) >= 2 * y) y1 = y1 + sign(y2 - y1) * 2 * y;
  if ((abs(x1 - x2) == x and abs(y1 - y2) == y) or (x1 == x2 and y1 == y2)) cout << "YES\n";
  else cout << "NO\n";
  return (0);
}
