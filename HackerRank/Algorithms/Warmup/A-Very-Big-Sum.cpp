/**
 * > Author: TISparta
 * > Date: 02-07-18
 * > Tags: Ad-Hoc
 * > Difficulty: 1 / 10
 */

#include <bits/stdc++.h>

using namespace std;

int main () {
  int n;
  long long num, ans = 0;
  cin >> n;
  while (n--) {
    cin >> num;
    ans += num;
  }
  cout << ans << endl;
  return (0);
}
