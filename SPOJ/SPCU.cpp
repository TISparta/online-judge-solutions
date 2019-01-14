/**
 * > Author: TISparta
 * > Date: 20-12-18
 * > Tags_ Ad-Hoc
 * > Difficulty: 2 / 10
 */

#include <bits/stdc++.h>

using namespace std;

bool readAndSolve () {
  int n;
  scanf("%d", &n);
  bool ret = true;
  for (int i = 0, a; i < n; i++) {
    scanf("%d", &a);
    ret &= (0 <= a and a <= i);
  }
  return ret;
}

int main () {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    puts(readAndSolve() ? "YES" : "NO");
  }
  return (0);
}
