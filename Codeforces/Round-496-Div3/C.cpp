// Brute Force
// 3
// 06-11-2020

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
  map <int, int> mp;
  vi a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]] += 1;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    bool ok = false;
    for (int bit = 0; bit < 32; bit++) {
      int y = (1 << bit) - a[i];
      if ((a[i] != y and mp.count(y)) or
          (a[i] == y and mp.count(y) and mp[y] > 1)) {
        ok = true;
        break;
      }
    }
    if (not ok) ans += 1;
  }
  cout << ans << '\n';
  return (0);
}
