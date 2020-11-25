// Binary Search
// 3
// 24-11-2020

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
  map <int, int> frec;
  for (int i = 0; i < n; i++) {
    int ai;
    cin >> ai;
    frec[ai] += 1;
  }
  vpii a;
  for (auto [x, y]: frec) a.emplace_back(y, x);
  sort(all(a));
  int l = 1, r = n;
  while (l != r) {
    int m = (l + r + 1) >> 1;
    int length = 0;
    for (auto [y, x]: a) {
      length += y / m;
    }
    if (length >= k) l = m;
    else r = m - 1;
  }
  vi ans;
  for (auto [y, x]: a) {
    int c = y / l;
    while (c--) ans.pb(x);
  }
  for (int i = 0; i < k; i++) cout << ans[i] << " \n"[i == k - 1];
  return (0);
}
