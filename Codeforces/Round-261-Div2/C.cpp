// Constructive Algorithms
// 5
// 01-11-2020

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
  ll n, d, k;
  cin >> n >> k >> d;
  auto die = [&] () {
    cout << -1 << '\n';
    exit(0);
  };
  ll jump = k;
  vector <vi> ans(d, vi(n));
  for (int i = 0; i < n; i++) {
    ans[0][i] = i % k + 1;
  }
  for (int i = 1; i < d; i++) {
    ans[i] = ans[i - 1];
    for (int j = 0; j < min(n, jump); j++) {
      ans[i][j] = 1;
      int s = 1 % k;
      for (int t = j + jump; t < n; t += jump) {
        ans[i][t] = s + 1;
        s = (s + 1) % k;
      }
    }
    jump = min(n, jump * k);
  }
  if (jump < n) die();
  for (int i = 0; i < d; i++) {
    for (int j = 0; j < n; j++) {
      cout << ans[i][j] << " \n"[j == n - 1];
    }
  }
  return (0);
}
