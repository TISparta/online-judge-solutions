#include <bits/stdc++.h>

using namespace std;

vector <int> Zfunction (string s) {
  int n = (int) s.size();
  vector <int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; i++) {
    if (i <= r) z[i] = min(r - i + 1, z[i - l]);
    while (i + z[i] < n and s[z[i]] == s[i + z[i]]) z[i]++;
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  return z;
}

int main () {
  string s;
  while (cin >> s, s[0] != '.') {
    int n = s.size();
    vector <int> z = Zfunction(s);
    int p = -1;
    for (int i = 1; i < n and p == -1; i++)
      if (n % i == 0 and z[i] + i == n) p = i;
    if (p == -1) p = n;
    cout << n / p << endl;
  }
  return (0);
}
