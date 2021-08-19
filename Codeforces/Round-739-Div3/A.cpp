// Tags: Brute Force
// Difficulty: 1.0
// Priority: 4
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
  auto check = [&] (int number) {
    string s = to_string(number);
    return (number % 3) and (s[sz(s) - 1] != '3');
  };
  vi ans;
  int cur = 0;
  while (sz(ans) < 1020) {
    cur += 1;
    if (check(cur)) ans.pb(cur);
  }
  int tt;
  cin >> tt;
  while (tt--) {
    int k;
    cin >> k;
    cout << ans[k - 1] << '\n';
  }
  return (0);
}
