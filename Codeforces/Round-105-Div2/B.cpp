// Implementation
// 2
// 16-01-2021

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
  ll vp, vd, t, f, c;
  cin >> vp >> vd >> t >> f >> c;
  if (vp >= vd) {
    cout << 0 << '\n';
    return (0);
  }
  double z = t * vp;
  for (int k = 0; ; k++) {
    double a = z / (vd - vp);
    z += a * vp;
    if (z > c - 1e-6) {
      cout << k << '\n';
      return (0);
    }
    z += vp * (z / vd + f);
  }
  return (0);
}
