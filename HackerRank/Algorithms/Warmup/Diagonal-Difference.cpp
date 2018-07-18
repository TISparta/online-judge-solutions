/**
 * > Author: TISparta
 * > Date: 02-07-18
 * > Tags: Ad-Hoc
 * > Difficulty: 1 / 10
 */

#include <bits/stdc++.h>

using namespace std;

int main () {
  int n, sum_1 = 0, sum_2 = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int num;
      cin >> num;
      if (i == j) sum_1 += num;
      if (i + j == n - 1) sum_2 += num;
    }
  }
  cout << abs(sum_1 - sum_2) << endl;
  return (0);
}
