#include <bits/stdc++.h>

using namespace std;

int main () {
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    vector <string> s;
    cin >> n;
    s.resize(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    sort(begin(s), end(s));
    bool ok = true;
    for (int i = 1; i < n and ok; i++)
      if (s[i - 1] == s[i].substr(0, s[i - 1].size())) ok = false;
    puts(ok ? "YES" : "NO");
  }
  return (0);
}
