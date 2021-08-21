// Tags: Implementation
// Difficulty: 1.0
// Priority: 5
// Date: 31-03-2019

#include <bits/stdc++.h>

#define all(A) begin(A), end(A)
#define sz(A) int(A.size())

using namespace std;

typedef long long ll;

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    string s;
    cin >> s;
    string p = s;
    sort(all(p));
    p.erase(unique(all(p)), end(p));
    bool ok = (sz(s) == sz(p));
    for (int i = 1; i < sz(p); i++) {
      ok &= (p[i] == p[i - 1] + 1);
    }
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return (0);
}
