// Implementation
// 2
// 08-01-2019

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
