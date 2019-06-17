/**
 * > Author : TISparta
 * > Date : 17-06-19
 * > Tags : Ad-Hoc
 * > Difficulty : 2 / 10
 */

#include <bits/stdc++.h>

#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    string s;
    cin >> n >> s;
    int have = count(all(s), 'P');
    int can = 0;
    for (int i = 2; i + 2 < n; i++) {
      bool flag1 = (s[i - 2] == 'P') or (s[i - 1] == 'P');
      bool flag2 = (s[i + 2] == 'P') or (s[i + 1] == 'P');
      if (s[i] == 'A' and flag1 and flag2) can++;
    }
    if (3 * n <= 4 * have) cout << 0 << '\n';
    else if (3 * n <= 4 * (have + can)) cout << (3 * n - 4 * have + 3) / 4 << '\n';
    else cout << -1 << '\n';
  }
  return (0);
}
