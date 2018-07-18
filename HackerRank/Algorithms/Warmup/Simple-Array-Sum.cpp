/**
 * > Author: TISparta
 * > Date: 02-07-18
 * > Tags: Ad-Hoc
 * > Difficulty: 1 / 10
 */

#include <bits/stdc++.h>

using namespace std;

int main () {
  int n, num, sum = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> num;
    sum += num;
  }
  cout << sum << endl;
  return (0);
}
