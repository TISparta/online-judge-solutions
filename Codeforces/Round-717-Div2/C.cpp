// DP, Brute Force
// 3.3
// 21-04-2021

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
  vi a(n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  vi valid(n, 1);
  auto check = [&] () {
    int sum = 0;
    for (int i = 0; i < n; i++) if (valid[i]) sum += a[i];
    if (sum & 1) return -1;
    int sum2 = sum / 2;
    vi dp(sum + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
      if (valid[i] == 0) continue;
      for (int x = sum - a[i]; x >= 0; x--) {
        if (dp[x]) dp[x + a[i]] = 1;
      }
      if (dp[sum2]) return i;
    }
    return -1;
  };
  if (check() == -1) {
    cout << 0 << '\n';
    return (0);
  }
  int take = -1;
  for (int i = 0; i < n; i++) {
    valid[i] = 0;
    if (check() == -1) {
      take = i + 1;
      break;
    }
    valid[i] = 1;
  }
  assert(take != -1);
  cout << 1 << '\n';
  cout << take << '\n';
  return (0);
}
