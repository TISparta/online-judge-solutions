// Tags: Implementation
// Difficulty: 1.5
// Priority: 5
// Date: 10-05-2021

#include <bits/stdc++.h>
     
#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())
#define pb push_back
#define mp make_pair
     
using namespace std;
     
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <pii> vpii;
typedef vector <pll> vpll;

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector <string> s(n);
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < m; c++) {
      if (s[r][c] == '.') s[r][c] = '0';
      if (not isdigit(s[r][c])) continue;
      char cnt = '0';
      for (int dr = -1; dr <= 1; dr++) {
        for (int dc = -1; dc <= 1; dc++) {
          if (dr == 0 and dc == 0) continue;
          int nr = r + dr;
          int nc = c + dc;
          if (not (0 <= min(nr, nc) and nr < n and nc < m)) continue;
          if (s[nr][nc] == '*') cnt += 1;
        }
      }
      if (cnt != s[r][c]) {
        cout << "NO\n";
        return (0);
      }
    }
  }
  cout << "YES\n";
  return (0);
}
