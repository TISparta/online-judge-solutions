// DP
// 3
// 13-09-2020

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
  vi x(n);
  for (int& xi: x) cin >> xi;
  vector <vpll> dp(n, vpll(n, pll(LLONG_MIN, LLONG_MIN)));
  function <pll(int,int)> rec = [&] (int l, int r) -> pll {
    if (l > r) return pll(0, 0);
    if (dp[l][r] != pll(LLONG_MIN, LLONG_MIN)) return dp[l][r];
    int ss = n - (r - l + 1);
    pll ret1 = rec(l + 1, r);
    if (ss % 2 == 0) ret1.first += x[l];
    else ret1.second += x[l];
    pll ret2 = rec(l, r - 1);
    if (ss % 2 == 0) ret2.first += x[r];
    else ret2.second += x[r];
    pll ret = ret1;
    if (ss % 2 == 0 and ret2 > ret1) ret = ret2;
    else if (ss % 2 == 1 and 
        (ret2.second > ret1.second or (ret2.second == ret1.second and ret2.first > ret1.second))) ret = ret2;
    return dp[l][r] = ret;
  };
  cout << rec(0, n - 1).first << '\n';
  return (0);
}
