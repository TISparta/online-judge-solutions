// Tags: Hashing, Binary Search
// Difficulty: 6.5
// Priority: 1
// Date: 18-06-2021

#include <bits/stdc++.h>
     
#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())
#define pb push_back
#define mp make_pair
     
using namespace std;
     
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <pii> vpii;
typedef vector <pll> vpll;

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector <int> zz(n);
  iota(all(zz), 1);
  vector <ull> H(n + 1, 0);
  const ull P = 251;
  const int N = 5e5 + 100;
  vector <ull> p(N, 0);
  p[0] = 1;
  for (int i = 1; i < N; i++) {
    p[i] = P * p[i - 1];
  }
  vector <vector <ull>> acc_p(n + 1);
  for (int len = 1; len <= n; len++) {
    acc_p[len].pb(p[0]);
    for (int x = len; x < N; x += len) {
      acc_p[len].pb(acc_p[len].back() + p[x]);
    }
  }
  for (int i = 1; i <= n; i++) {
    ull val = s[i - 1] - 'a' + 1;
    H[i] = H[i - 1] + p[i - 1] * val;
  }
  auto get_hash = [&] (int x, int len) {
    ull hh = 0;
    if (len >= x) {
      hh = acc_p[x][len / x - 1] * H[x];
    }
    if (len % x) {
      hh = hh + p[x * (len / x)] * H[len % x];
    }
    return hh;
  };
  auto lt = [&] (int x, int y) {
    if (get_hash(x, k) == get_hash(y, k)) return x < y;
    int lo = min(x, y), hi = k;
    while (lo != hi) {
      int mid = (lo + hi) >> 1;
      if (get_hash(x, mid) == get_hash(y, mid)) lo = mid + 1;
      else hi = mid;
    }
    lo -= 1;
    return s[lo % x] < s[lo % y];
    /*
    string a = s.substr(0, x);
    string b = s.substr(0, y);
    while (sz(a) < n) a += a;
    while (sz(b) < n) b += b;
    return a < b;
    */
  };
  int best = 1;
  for (int i = 2; i <= n; i++) if (lt(i, best)) best = i;
  string z = s.substr(0, best);
  while (sz(z) < k) z += z;
  for (int i = 0; i < k; i++) cout << z[i % sz(z)];
  cout << '\n';
  return (0);
}
