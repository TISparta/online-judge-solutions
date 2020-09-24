// Brute Force
// 2
// 11-09-2020

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
  vi a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  pii ans(INT_MAX, -1);
  for (int a0 = 1; a0 <= 1000; a0++) {
    int cur = a0;
    int need = 0;
    for (int i = 0; i < n; i++) {
      if (cur != a[i]) need += 1;
      cur += k;
    }
    ans = min(ans, pii(need, a0));
  }
  cout << ans.first << '\n';
  int cur = ans.second;
  for (int i = 0; i < n; i++) {
    if (cur < a[i]) {
      cout << "- " << i + 1 << " " << abs(cur - a[i]) << '\n';
    } else if (cur > a[i]) {
      cout << "+ " << i + 1 << " " << abs(cur - a[i]) << '\n';
    }
    cur += k;
  }
  return (0);
}
