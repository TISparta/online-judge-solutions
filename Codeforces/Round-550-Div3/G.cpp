// Tags: Greedy
// Difficulty: 6.0
// Priority: 1
// Date: 20-08-2021

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
  int n;
  cin >> n;
  vi a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vi inc = {INT_MIN};
  vi dec = {INT_MAX};
  vi ans(n, 1);
  for (int i = 0; i < n; i++) {
    bool b1 = (inc.back() < a[i]);
    bool b2 = (dec.back() > a[i]);
    if (b1 + b2 == 0) {
      cout << "NO\n";
      return (0);
    }
    if (b1 and not b2) {
      inc.pb(a[i]);
      ans[i] = 0;
    } else if(not b1 and b2) {
      dec.pb(a[i]);
    } else {
      if (i + 1 == n) {
        inc.pb(a[i]);
        ans[i] = 0;
      } else {
        if (a[i] < a[i + 1]) inc.pb(a[i]), ans[i] = 0;
        else dec.pb(a[i]);
      }
    }
  }
  cout << "YES\n";
  for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i + 1 == n];
  return (0);
}
