/**
 * > Author: TISparta
 * > Date: 24-12-18
 * > Tags: Ad-Hoc
 * > Difficulty: 1 / 10
 */

#include <bits/stdc++.h>

using namespace std;

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int pos;
  cin >> pos;
  for (int i = 0; i < 3; i++) {
    int x, y;
    cin >> x >> y;
    if (x == pos) pos = y;
    else if (y == pos) pos = x;
  }
  cout << pos << endl;
  return (0);
}
