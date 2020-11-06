// Sorting
// 5
// 12-08-2020

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
  vi a(n + 1);
  int x = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] == m) x = i;
  }
  map <int, int> dif;
  int lt = 0, gt = 0;
  dif[0] = 1;
  for (int i = x - 1; i >= 1; i--) {
    if (a[i] > m) gt++;
    if (a[i] < m) lt++;
    dif[gt - lt]++;
  }
  ll ans = dif[0] + dif[1];
  lt = 0, gt = 0;
  for (int i = x + 1; i <= n; i++) {
    if (a[i] > m) gt++;
    if (a[i] < m) lt++;
    int d = gt - lt;
    ans += dif[-d];
    ans += dif[1 - d];
  }
  cout << ans << '\n';
  return (0);
}
