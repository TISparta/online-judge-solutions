// Implementation
// 3
// 12-03-2020

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
  int k;
  cin >> k;
  map <int, vpii> mp;
  for (int i = 1; i <= k; i++) {
    int n;
    cin >> n;
    vi arr(n);
    for (int& elem: arr) cin >> elem;
    int sum = accumulate(all(arr), 0);
    for (int j = 0; j < n; j++) {
      if (mp[sum - arr[j]].empty() or
          mp[sum - arr[j]].back().first != i) {
        mp[sum - arr[j]].pb(pii(i, j + 1));
      }
    }
  }
  for (auto row: mp) {
    if (sz(row.second) >= 2) {
      auto pp = row.second[0];
      auto qq = row.second[1];
      cout << "YES\n";
      cout << pp.first << ' ' << pp.second << '\n';
      cout << qq.first << ' ' << qq.second << '\n';
      return (0);
    }
  }
  cout << "NO\n";
  return (0);
}
