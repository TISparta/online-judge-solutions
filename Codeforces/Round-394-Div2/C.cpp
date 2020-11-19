// Brute Force
// 2
// 19-11-2020

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
  const int INF = 1e7;
  vi a(n, INF);
  vi b(n, INF);
  vi c(n, INF);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      if (isdigit(s[j])) {
        a[i] = min(a[i], min(j, m - j));
      }
      if ('a' <= s[j] and s[j] <= 'z') {
        b[i] = min(b[i], min(j, m - j));
      }
      if (s[j] == '#' or s[j] == '*' or s[j] == '&') {
        c[i] = min(c[i], min(j, m - j));
      }
    }
  }
  int ans = INF;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        if (i == j or i == k or j == k) continue;
        ans = min(ans, a[i] + b[j] + c[k]);
      }
    }
  }
  cout << ans << '\n';
  return (0);
}
