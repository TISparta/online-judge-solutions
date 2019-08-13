/**
 * > Author : TISparta
 * > Date : 02-08-19
 * > Tags : Math
 * > Difficulty : 3 / 10
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
    string s;
    cin >> s;
    if (count(all(s), '1') % 2) cout << "WIN\n";
    else cout << "LOSE\n";
  }
  return (0);
}
