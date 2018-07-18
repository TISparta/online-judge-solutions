/**
 * > Author: TISparta
 * > Date: 02-07-18
 * > Tags: Ad-Hoc
 * > Difficulty: 1 / 10
 */

#include <bits/stdc++.h>

using namespace std;

int main () {
  int n, num, pos = 0, zero = 0, neg = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> num;
    if (num > 0) pos++;
    else if (num < 0) neg++;
    else zero++;
  }
  cout << fixed << setprecision(6) << 1.0 * pos / n << endl << 1.0 * neg / n << endl << 1.0 * zero / n << endl;
  return (0);
}
