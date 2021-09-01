// Tags: Z Function
// Difficulty: 5.0
// Priority: 1
// Date: 31-08-2021

#include <bits/stdc++.h>
     
#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple

using namespace std;
     
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <pii> vpii;
typedef vector <pll> vpll;

vector <int> Z_function (const string& s) {
  int n = (int) s.size();
  vector <int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; i++) {
    if (i <= r) z[i] = min(r - i + 1, z[i - l]);
    while (i + z[i] < n and s[z[i]] == s[i + z[i]]) z[i]++;
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  return z;
}

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  int ans = 0;
  for (int len = 1; len <= n; len++) {
    string ss = s.substr(n - len);
    ss += '#';
    ss += ss;
    ss.pop_back();
    vi z = Z_function(ss);
    for (int i = len + 1; i < sz(z); i++) {
      int can = i - len - 1;
      ans = max(ans, min(z[i], can));
    }
  }
  cout << ans << '\n';
  return (0);
}
