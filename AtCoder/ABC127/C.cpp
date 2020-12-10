// Cummulative Sums
// 1
// 09-12-2020

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
  int n, m;
  cin >> n >> m;
  vi acc(n + 2, 0);
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    acc[l] += 1;
    acc[r + 1] -= 1;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    acc[i] += acc[i - 1];
    if (acc[i] == m) ans += 1;
  }
  cout << ans << '\n';
  return (0);
}
