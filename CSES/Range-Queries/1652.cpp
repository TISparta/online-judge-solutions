// Cummulative Sums
// 2
// 21-09-2020

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
  int n, q;
  cin >> n >> q;
  vector <vi> acc(n + 1, vi(n + 1, 0));
  for (int r = 1; r <= n; r++) {
    string s;
    cin >> s;
    for (int c = 1; c <= n; c++) {
      acc[r][c] = acc[r][c - 1] + acc[r - 1][c] - acc[r - 1][c - 1];
      if (s[c - 1] == '*') acc[r][c] += 1;
    }
  }
  while (q--) {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    cout << acc[r2][c2] - acc[r2][c1 - 1] - acc[r1 - 1][c2] + acc[r1 - 1][c1 - 1] << '\n';
  }
  return (0);
}
