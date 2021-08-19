// Tags: Greedy
// Difficulty: 5.3
// Priority: 4
// Date: 17-08-2020

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
  vi t(n);
  vi T(n);
  vi x(n);
  vi cost(n);
  for (int i = 0; i < n; i++) cin >> t[i] >> T[i] >> x[i] >> cost[i];
  auto gaaaaa = [&] (int i, int b) {
    pii b1; // (cnt, number_bus)
    pii b2; // (cnt, number_bus)
    if (m % b == 0) {
      b1 = pii(m / b, b);
      b2 = pii(0, 0);
    } else {
      int left = m % b;
      b1 = pii(m / b + 1, left);
      b2 = pii(m / b, b - left);
    }
    ll money = 1LL * cost[i] * b;
    if (t[i] + b1.first > T[i]) {
      money += 1LL * x[i] * b1.first * b1.second;
    }
    if (t[i] + b2.first > T[i]) {
      money += 1LL * x[i] * b2.first * b2.second;
    }
    return money;
  };
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ll add = gaaaaa(i, 1);
    if (t[i] < T[i]) {
      int z = m / (T[i] - t[i]);
      for (int zz: {z - 1, z, z + 1}) {
        if (zz <= 0) continue;
        add = min(add, gaaaaa(i, zz));
      }
    }
    ans += add;
  }
  cout << ans << '\n';
  return (0);
}
