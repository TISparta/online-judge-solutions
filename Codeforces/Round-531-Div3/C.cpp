/**
 * > Author: TISparta
 * > Date: 09-01-19
 * > Tags: Game Theory
 * > Difficulty: 3 / 10
 */

#include <bits/stdc++.h>

using namespace std;

int main () {
  int n, x, y;
  cin >> n >> x >> y;
  vector <int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(begin(a), end(a));
  int ans = 0;
  bool second = false;
  for (int a_i: a) {
    if (a_i <= x) {
      if (second) a_i += y, second = false;
      else second = true;
      if (x > y or a_i <= x) ans++;
    }
    else if (x > y) ans++;
  }
  cout << ans << endl;
  return (0);
}
