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
  vector <int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  int mx = *max_element(begin(arr), end(arr));
  cout << count(begin(arr), end(arr), mx) << endl;
  return (0);
}
