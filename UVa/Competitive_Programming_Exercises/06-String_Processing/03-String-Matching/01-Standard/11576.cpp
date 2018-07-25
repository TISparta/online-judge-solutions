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
  int tc;
  cin >> tc;
  while (tc--) {
    int n, k, ans = 0;
    cin >> k >> n;
    string prev, curr;
    cin >> prev;
    ans = prev.size();
    for (int i = 1; i < n; i++) {
      cin >> curr;
      ans += k - prefixFunction(curr + '#' + prev);
      prev = curr;
    }
    cout << ans << endl;
  }
  return (0);
}
