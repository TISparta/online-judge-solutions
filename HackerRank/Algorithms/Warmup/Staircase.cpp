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
  cin >> n;
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < n; c++) {
      putchar(c >= n - 1 - r ? '#' : ' ');
    }
    putchar('\n');
  }
  return (0);
}
