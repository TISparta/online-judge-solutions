/**
 * > Author: TISparta
 * > Date: 08-01-19
 * > Tags: Implementation
 * > Difficulty: 2 / 10
 */

#include <bits/stdc++.h>

using namespace std;

int main () {
  int n;
  string s;
  cin >> n >> s;
  for (int d = 1; d <= n; d++) if (n % d == 0) reverse(begin(s), begin(s) + d);
  cout << s << endl;
  return  (0);
}
