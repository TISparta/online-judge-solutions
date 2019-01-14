/**
 * > Author: TISparta
 * > Date: 09-01-19
 * > Tags: Ad-Hoc
 * > Difficulty: 1 / 10
 */

#include <bits/stdc++.h>

using namespace std;

int main () {
  int n;
  cin >> n;
  if (n % 4 == 0 or n % 4 == 3) cout << 0 << endl;
  else cout << 1 << endl;
  return (0);
}
