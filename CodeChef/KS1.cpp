/**
 * > Author : TISparta
 * > Date : 02-08-19
 * > Tags : Cummulative Sums
 * > Difficulty : 4 / 10
 */

#include <bits/stdc++.h>

#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    map <int, pair <int, ll>> frec;
    int acc = 0;
    ll ans = 0;
    frec[acc] = {1, 1};
    for (int i = 1; i <= n; i++) {
      int a;
      cin >> a;
      acc ^= a;
      if (frec.count(acc)) {
        auto pp = frec[acc];
        ans += 1LL * i * pp.first - pp.second;
      }
      frec[acc].first++;
      frec[acc].second += i + 1;
    }
    cout << ans << '\n';
  }
  return (0);
}
