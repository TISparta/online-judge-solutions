// 4
// DP
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
  vector <tuple <int, int, int>> arr(n);
  for (int i = 0; i < n; i++) {
    int a, b, p;
    cin >> a >> b >> p;
    arr[i] = make_tuple(a, b, p);
  }
  sort(all(arr));
  vi nxt(n);
  set <pii> st = {pii(INT_MAX, n)};
  for (int i = n - 1; i >= 0; i--) {
    int r = st.upper_bound(pii(get <1> (arr[i]), INT_MAX))->second;
    nxt[i] = r;
    st.insert(pii(get <0> (arr[i]), i));
  }
  vll dp(n, -1);
  function <ll(int)> rec = [&] (int pos) -> ll {
    if (pos == n) return 0LL;
    if (dp[pos] != -1) return dp[pos];
    return dp[pos] = max(rec(pos + 1), get <2> (arr[pos]) + rec(nxt[pos]));
  };
  cout << rec(0) << '\n';
  return (0);
}
