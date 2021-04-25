// Math
// 4.0
// 19-04-2021

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

int mod(int a, int m) {                          // returns a (mod m)
  return ((a%m) + m) % m;                        // ensure positive answer
}

int modPow(int b, int p, int m) {                // assume 0 <= b < m
  if (p == 0) return 1;
  int ans = modPow(b, p/2, m);                   // this is O(log p)
  ans = mod(ans*ans, m);                         // double it first
  if (p&1) ans = mod(ans*b, m);                  // *b if p is odd
  return ans;                                    // ans always in [0..m-1]
}

int extEuclid(int a, int b, int &x, int &y) {    // pass x and y by ref
  int xx = y = 0;
  int yy = x = 1;
  while (b) {                                    // repeats until b == 0
    int q = a/b;
    tie(a, b) = tuple(b, a%b);
    tie(x, xx) = tuple(xx, x-q*xx);
    tie(y, yy) = tuple(yy, y-q*yy);
  }
  return a;                                      // returns gcd(a, b)
}

int modInverse(int b, int m) {                   // returns b^(-1) (mod m)
  int x, y;
  int d = extEuclid(b, m, x, y);                 // to get b*x + m*y == d
  if (d != 1) return -1;                         // to indicate failure
  // b*x + m*y == 1, now apply (mod m) to get b*x == 1 (mod m)
  return mod(x, m);
}

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  /*
  int n;
  cin >> n;
  vi ans;
  for (int mask = 1; mask < (1 << n); mask++) {
    vi take;
    for (int bit = 0; bit < n; bit++) {
      if ((mask >> bit) & 1) take.pb(1 + bit);
    }
    int z = 1;
    for (int ai: take) {
      z = (1LL * z * ai) % n;
    }
    if (z == 1 and sz(take) > sz(ans)) ans = take;
  }
  cout << sz(ans) << '\n';
  for (int ai: ans) cout << ai << ' ';
  cout << '\n';
  int f = 1;
  */
  int n;
  cin >> n;
  vi ans;
  int f = 1;
  for (int i = 1; i <= n; i++) {
    int j = modInverse(i, n);
    if (j != -1) {
      ans.pb(i);
      f = (1LL * f * i) % n;
    }
  }
  if (f != 1) {
    ans.pop_back();
  }
  f = 1;
  cout << sz(ans) << '\n';
  for (int ai: ans) {
    f = (1LL * f * ai) % n;
    cout << ai << ' ';
  }
  cout << '\n';
  assert(f == 1);
  return (0);
}
