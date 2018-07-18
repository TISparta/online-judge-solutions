/**
 * > Author: TISparta
 * > Date: 02-07-18
 * > Tags: Ad-Hoc
 * > Difficulty: 1 / 10
 */

#include <bits/stdc++.h>

using namespace std;

int main () {
  int ans_1 = 0, ans_2 = 0;
  vector <int> a(3), b(3);
  for (int i = 0; i < 3; i++) cin >> a[i];
  for (int i = 0; i < 3; i++) cin >> b[i];
  for (int i = 0; i < 3; i++) {
    if (a[i] > b[i]) ans_1++;
    else if (a[i] < b[i]) ans_2++;
  }
  cout << ans_1 << ' ' << ans_2 << endl;
  return (0);
}
