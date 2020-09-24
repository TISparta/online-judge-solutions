// DP
// 2
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
  int n, x;
  cin >> n >> x;
  vi dp(x + 1, 0);
  vi h(n);
  vi s(n);
  for (int i = 0; i < n; i++) cin >> h[i];
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 0; i < n; i++) {
    for (int j = x - h[i]; j >= 0; j--) {
      dp[j + h[i]] = max(dp[j + h[i]], dp[j] + s[i]);
    }
  }
  cout << *max_element(all(dp)) << '\n';
  return (0);
}
