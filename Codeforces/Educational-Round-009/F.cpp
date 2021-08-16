// Tags: Brute Force, Bitmaks
// Difficulty: 7.0
// Priority: 1
// Date: 15-08-2021

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

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  vector <vi> mat(n, vi(n));
  vi val;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> mat[i][j];
      val.pb(mat[i][j]);
    }
  }
  bool ok = true;
  for (int i = 0; i < n; i++) {
    ok &= (mat[i][i] == 0);
    for (int j = 0; j < n; j++) {
      ok &= (mat[i][j] == mat[j][i]);
    }
  }
  if (not ok) {
    cout << "NOT MAGIC\n";
    return (0);
  }
  sort(all(val));
  val.erase(unique(all(val)), end(val));
  vector <vpii> z(sz(val));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      mat[i][j] = lower_bound(all(val), mat[i][j]) - begin(val);
      z[mat[i][j]].eb(i, j);
    }
  }
  const int N = 2500;
  vector <bitset <N>> mask(n);
  vi updated(n, 0);
  for (int i = 0; i < sz(val) and ok; i++) {
    for (auto [r, c]: z[i]) {
      if (updated[r] == 0 and updated[c] == 0) continue;
      ok &= ((mask[r] & mask[c]).count() == 0);
      if (not ok) break;
    }
    for (auto [r, c]: z[i]) {
      updated[r] = 1;
      mask[r][c] = 1;
    }
  }
  if (ok) cout << "MAGIC\n";
  else cout << "NOT MAGIC\n";
  return (0);
}
