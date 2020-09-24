// Brute Force
// 3
// 09-09-2020

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
  int n, x;
  cin >> n >> x;
  vi a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  map <int, vpii> pos;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      pos[a[i] + a[j]].pb(pii(i, j));
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int need = x - a[i] - a[j];
      auto it = upper_bound(all(pos[need]), pii(j, n));
      if (it != end(pos[need])) {
        int k, l;
        tie(k, l) = *it;
        cout << i << ' ' << j << ' ' << k << ' ' << l << '\n';
        return (0);
      }
    }
  }
  cout << "IMPOSSIBLE\n";
  return (0);
}
