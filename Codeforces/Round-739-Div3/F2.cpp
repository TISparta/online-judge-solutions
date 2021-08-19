// Tags: Brute Force
// Difficulty: 5.3
// Priority: 2
// Date: 18-08-2021

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

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    int k;
    cin >> s >> k;
    set <int> used(all(s));
    if (sz(used) <= k) {
      cout << s << '\n';
      continue;
    }
    int len = sz(s);
    set <int> tmp;
    int pos = 0;
    string num(len, ' ');
    while (pos < len and sz(tmp) != k - 1) {
      num[pos] = s[pos];
      tmp.emplace(s[pos] - '0');
      pos += 1;
    }
    vi digits(all(tmp));
    string ans(len, '9');
    for (int dd = 0; dd <= 9; dd++) {
      digits.pb(dd);
      for (int i = pos; i < len; i++) {
        int mn = 10;
        for (int d: digits) if (s[i] - '0' < d) mn = min(mn, d);
        if (mn == 10) continue;
        num[i] = mn + '0';
        bool ok = true;
        for (int j = pos; j < i; j++) {
          int mn = 10;
          for (int d: digits) if (s[j] - '0' <= d) mn = min(mn, d);
          ok &= (mn != 10);
          num[j] = mn + '0';
        }
        for (int j = i + 1; j < len; j++) {
          int mn = *min_element(all(digits));
          num[j] = mn + '0';
        }
        if (ok and num >= s) ans = min(ans, num);
      }
      digits.pop_back();
    }
    cout << ans << '\n';
  }
  return (0);
}
