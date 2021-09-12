// Tags: Cumulative Array
// Difficulty: 3.0
// Priority: 4
// Date: 30-07-2021

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
    int m;
    cin >> m;
    vector <vll> a(2, vll(m + 2, 0));
    for (int i = 0; i < 2; i++) {
      for (int j = 1; j <= m; j++) {
        cin >> a[i][j];
      }
    }
    vll s1(m + 2, 0);
    for (int j = m; j >= 1; j--) {
      s1[j] = s1[j + 1] + a[0][j];
    }
    vll s2(m + 2, 0);
    for (int j = 1; j <= m; j++) {
      s2[j] = s2[j - 1] + a[1][j];
    }
    ll ans = LLONG_MAX;
    for (int j = 1; j <= m; j++) {
      ans = min(ans, max(s1[j + 1], s2[j - 1]));
    }
    cout << ans << '\n';
  }
  return (0);
}
