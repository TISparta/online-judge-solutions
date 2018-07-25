#include <bits/stdc++.h>

using namespace std;

vector <int> prefixFunction (const string s) {
  int n = s.size();
  vector <int> pi(n);
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j > 0 and s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }
  return pi;
}

int main () {
  int tc;
  string s;
  cin >> tc;
  while (tc--) {
    cin >> s;
    string rs = s;
    reverse(begin(rs), end(rs));
    vector <int> pi = prefixFunction(s + '#' + rs);
    int key_len = *max_element(begin(pi) + s.size(), end(pi));
    string key = s.substr(0, key_len);
    reverse(begin(key), end(key));
    cout << key << endl;
  }
  return (0);
}
