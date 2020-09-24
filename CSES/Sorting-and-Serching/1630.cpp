// Greedy
// 2
// 05-09-2020

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
  int n;
  cin >> n;
  vpii arr(n);
  for (auto& pp: arr) cin >> pp.first >> pp.second;
  sort(all(arr));
  ll ans = 0;
  ll cur = 0;
  for (auto pp: arr) {
    cur += pp.first;
    ans += pp.second - cur;
  }
  cout << ans << '\n';
  return (0);
}
