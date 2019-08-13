/**
 * > Author : TISparta
 * > Date : 02-08-19
 * > Tags : Brute Force
 * > Difficulty : 3 / 10
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
    vector <int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    int ans = 0;
    for (int i = 0; i < n; i++) ans = max(ans, 20 * a[i] - 10 * b[i]);
    cout << ans << '\n';
  }
  return (0);
}
