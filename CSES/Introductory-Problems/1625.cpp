// Backtracking, Heavy Prunning
// 6
// 05-09-2020

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

string s;
bool vis[7][7];
inline bool valid (int r, int c) { return (0 <= r and 0 <= c and r < 7 and c < 7 and not vis[r][c]); }

int backtrack (int pos, int r, int c, int last) {
  if (r == 6 and c == 0) return (pos == sz(s));
  if (last != 2 and not valid(r, c + 1) and valid(r - 1, c) and valid(r + 1, c)) return 0;
  if (last != 3 and not valid(r + 1, c) and valid(r, c - 1) and valid(r, c + 1)) return 0;
  if (last != 0 and not valid(r, c - 1) and valid(r - 1, c) and valid(r + 1, c)) return 0;
  if (last != 1 and not valid(r - 1, c) and valid(r, c - 1) and valid(r, c + 1)) return 0;
  vis[r][c] = true;
  int ret = 0;
  if ((s[pos] == '?' or s[pos] == 'R') and valid(r, c + 1)) ret += backtrack(pos + 1, r, c + 1, 0);
  if ((s[pos] == '?' or s[pos] == 'D') and valid(r + 1, c)) ret += backtrack(pos + 1, r + 1, c, 1);
  if ((s[pos] == '?' or s[pos] == 'L') and valid(r, c - 1)) ret += backtrack(pos + 1, r, c - 1, 2);
  if ((s[pos] == '?' or s[pos] == 'U') and valid(r - 1, c)) ret += backtrack(pos + 1, r - 1, c, 3);
  vis[r][c] = false;
  return ret;
}

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> s;
  cout << backtrack(0, 0, 0, -1) << '\n';
  return (0);
}
