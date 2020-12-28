// Linear Algebra
// 6
// 28-12-2020

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
  int n;
  cin >> n;
  int acc = 0;
  const int D = 31;
  vi basis(D, 0);
  int ans = 0;
  auto add_vector = [&] (int mask) {
    for (int bit = 0; bit < D; bit++) {
      int bi = (mask >> bit) & 1;
      if (bi == 0) continue;
      if (basis[bit] == 0) {
        basis[bit] = mask;
        ans += 1;
        return;
      }
      mask ^= basis[bit];
    }
  };
  for (int i = 0; i < n; i++) {
    int ai;
    cin >> ai;
    acc ^= ai;
    add_vector(ai);
  }
  if (acc == 0) cout << -1 << '\n';
  else cout << ans << '\n';
  return (0);
}
