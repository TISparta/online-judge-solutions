// Tags: Math
// Difficulty: 2.0
// Priority: 3
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
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vi frec(m, 0);
    for (int i = 0; i < n; i++) {
      int ai;
      cin >> ai;
      frec[ai % m] += 1;
    }
    int need = 0;
    if (frec[0]) need += 1;
    for (int i = 1; i + i < m; i++) {
      int x = frec[i];
      int y = frec[m - i];
      if (x == 0 and y == 0) continue;
      need += 1;
      int z = min(x, y) + 1;
      x -= z;
      y -= z;
      need += max({0, x, y});
    }
    if (m % 2 == 0 and frec[m / 2]) need += 1;
    cout << need << '\n';
  }
  return (0);
}
