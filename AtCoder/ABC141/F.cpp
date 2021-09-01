// Tags: Linear Algebra
// Difficulty: 5.5
// Priority: 1
// Date: 01-09-2021

#include <bits/stdc++.h>
     
#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple

using namespace std;
     
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <pii> vpii;
typedef vector <pll> vpll;

struct XorBase {
  const int LG = 63;
  vll basis;
  XorBase () { basis = vll(LG, 0); }

  void add_vector (ll mask) {
    for (int bit = LG - 1; bit >= 0; bit--) {
      if (((mask >> bit) & 1) == 0) continue;
      if (basis[bit] == 0) {
        basis[bit] = mask;
        return;
      }
      mask ^= basis[bit];
    }
  }

  ll max_xor () {
    ll mask = 0;
    for (int bit = LG - 1; bit >= 0; bit--) {
      if (basis[bit] == 0) continue;
      if (((mask >> bit) & 1) == 0) mask ^= basis[bit];
    }
    return mask;
  }
};

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  vll a(n);
  ll total = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    total ^= a[i];
  }
  ll ans = 0;
  for (int bit = 0; bit < 60; bit++) {
    if (((total >> bit) & 1) == 0) continue;
    ans += (1LL << bit);
    for (int i = 0; i < n; i++) {
      if ((a[i] >> bit) & 1) a[i] -= (1LL << bit);
    }
  }
  XorBase xorbase;
  for (auto ai: a) xorbase.add_vector(ai);
  ans = ans + 2 * xorbase.max_xor();
  cout << ans << '\n';
  return (0);
}
