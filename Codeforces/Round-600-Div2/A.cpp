// Tags: Implementation
// Difficulty: 1.5
// Priority: 2
// Date: 17-11-2021

#include <bits/stdc++.h>

#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector <int> a(n), b(n);
    for (int& elem: a) cin >> elem;
    for (int& elem: b) cin >> elem;
    vector <int> diff(n);
    for (int i = 0; i < n; i++) diff[i] = b[i] - a[i];
    bool ok = true;
    int cnt = 0;
    for (int i = 0; i < n; ) {
      if (diff[i] < 0) {
        ok = false;
        break;
      }
      if (diff[i] == 0) {
        i++;
        continue;
      }
      if (cnt == 1) {
        ok = false;
        break;
      }
      int j = i;
      while (j + 1 < n and diff[j + 1] == diff[i]) j++;
      i = j + 1;
      cnt++;
    }
    if (ok) cout << "YES\n";
    else cout << "NO\n";
  }
  return (0);
}
