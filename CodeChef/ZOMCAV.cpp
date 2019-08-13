/**
 * > Author : TISparta
 * > Date : 02-08-19
 * > Tags : Sorting, Cummulative Sums
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
    vector <int> acc(n + 2);
    for (int i = 1; i <= n; i++) {
      int c;
      cin >> c;
      int from = max(1, i - c);
      int to = min(n, i + c);
      acc[from] += 1;
      acc[to + 1] += -1;
    }
    vector <int> x;
    for (int i = 1; i <= n; i++) {
      acc[i] += acc[i - 1];
      x.push_back(acc[i]);
    }
    vector <int> y(n);
    for (int i = 0; i < n; i++) cin >> y[i];
    sort(all(x));
    sort(all(y));
    if (x == y) cout << "YES\n";
    else cout << "NO\n";
  }
  return (0);
}
