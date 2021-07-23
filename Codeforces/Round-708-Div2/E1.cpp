// Tags: Math
// Difficulty: 6.0
// Priority: 2
// Date: 17-03-2021

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
  const int N = 1e7 + 1;
  vi f(N, 0);
  for (int u = 2; u < N; u++) {
    if (f[u] != 0) continue;
    for (int v = u; v < N; v += u) {
      f[v] = u;
    }
  }
  f[1] = 1;
  auto get = [&] (int a) {
    int rep = 1;
    while (a != 1) {
      int z = f[a];
      int e = 0;
      while (a % z == 0) {
        e += 1;
        a /= z;
      }
      if (e & 1) rep *= z;
    }
    return rep;
  };
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    set <int> zz;
    int ans = 1;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      int rep = get(a);
      if (zz.count(rep)) {
        ans += 1;
        zz.clear();
      }
      zz.emplace(rep);
    }
    cout << ans << '\n';
  }
  return (0);
}
