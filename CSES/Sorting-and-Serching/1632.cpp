// Greedy
// 3
// 12-09-2020

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
  int n, k;
  cin >> n >> k;
  vpii arr(n);
  for (auto& pp: arr) cin >> pp.first >> pp.second;
  sort(all(arr), [&] (pii pp, pii qq) { 
    if (pp.second != qq.second) return pp.second < qq.second;
    return pp.first < qq.first;
  });
  multiset <int> cur;
  for (int i = 0; i < k; i++) cur.insert(-1e9);
  int ans = 0;
  for (auto pp: arr) {
    if (*begin(cur) <= pp.first) {
      ans += 1;
      cur.erase(--cur.upper_bound(pp.first));
      cur.insert(pp.second);
    }
  }
  cout << ans << '\n';
  return (0);
}
