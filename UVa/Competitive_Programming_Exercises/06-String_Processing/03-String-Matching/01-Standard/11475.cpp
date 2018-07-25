#include <bits/stdc++.h>

using namespace std;

int prefixFunction (const string s) {
  int n = s.size();
  vector <int> pi(n);
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j > 0 and s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }
  return pi.back();
}

int main () {
  string s;
  while (cin >> s) {
    string rs = s;
    reverse(begin(rs), end(rs));
    rs += '#';
    rs.append(s);
    int p_len = prefixFunction(rs);
    cout << s;
    for (int i = s.size() - p_len - 1; i >= 0; i--) cout << s[i];
    cout << endl;
  }
  return (0);
}
