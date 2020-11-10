// Math
// 3
// 30-09-2020

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
  ll k;
  cin >> k;
  ll init = 1;
  ll add = 9;
  ll sum = 0;
  // 9
  // 9 * 10 * 2
  // 9 * 10 * 10 * 3
  // 9 * 10 * 10 * 4
  for (ll len = 1; ; len++) {
    if (sum + add * len < k) {
      sum += add * len;
      add *= 10;
      init *= 10;
    } else {
      // 10, 11 -> 0
      // 12, 13 -> 1
      // 14, 15 -> 2
      ll x = (k - sum - 1) / len;
      ll num = init + x;
      k = (k - sum - 1) % len;
      string s = to_string(num);
      cout << s[k] << '\n';
      break;
    }
  }
  return (0);
}
