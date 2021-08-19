// Tags: Brute Force
// Difficulty: 5.0
// Priority: 3
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
    int val = stoi(s);
    int len = sz(s);
    int ans = INT_MAX;
    for (int d = 1; d <= 9; d++) {
      int num = d;
      for (int i = 1; i < len; i++) num = num * 10 + d;
      if (num >= val) ans = min(ans, num);
    }
    if (k == 2) {
      for (int d = 1; d <= 9; d++) {
        int num = d;
        for (int i = 1; i < len; i++) num = num * 10;
        if (num >= val) ans = min(ans, num);
      }
      int c1 = s[0] - '0';
      for (int c2 = 0; c2 <= 9; c2++) {
        if (c1 == c2) continue;
        for (int mask = 0; mask < (1 << (len - 1)); mask++) {
          int num = c1;
          for (int bit = 0; bit < len - 1; bit++) {
            if ((mask >> bit) & 1) num = num * 10 + c1;
            else num = num * 10 + c2;
          }
          if (num >= val) ans = min(ans, num);
        }
      }
    }
    cout << ans << '\n';
  }
  return (0);
}
