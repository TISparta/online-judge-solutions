// Two Pointers
// 3
// 13-10-2020

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
  for (int i = 0; i < n; i++) cin >> a[i];
  int ans = 1;
  vpii arr;
  for (int l = 0; l < n; l++) {
    int r = l;
    while (r + 1 < n and a[r] < a[r + 1]) r++;
    arr.emplace_back(l, r);
    ans = max(ans, r - l + 1);
    l = r;
  }
  for (int i = 0; i + 1 < sz(arr); i++) {
    auto [l1, r1] = arr[i];
    auto [l2, r2] = arr[i + 1];
    // delete r1
    if (l1 < r1 and a[r1 - 1] < a[l2]) {
      ans = max(ans, (r2 - l2 + 1) + (r1 - l1 + 1) - 1);
    }
    // delete l2
    if (l2 < r2) {
      if (a[r1] < a[l2 + 1]) {
        ans = max(ans, (r2 - l2 + 1) + (r1 - l1 + 1) - 1);
      }
    } else if (i + 2 < sz(arr)) {
      auto [l3, r3] = arr[i + 1];
      if (a[r1] < a[l3]) {
        ans = max(ans, (r3 - l3 + 1) + (r1 - l1 + 1));
      }
    }
  }
  cout << ans << '\n';
  return (0);
}
