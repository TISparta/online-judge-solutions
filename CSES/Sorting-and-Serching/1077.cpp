// Implementation
// 4
// 12-09-2020

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
  vi arr(begin(a), begin(a) + k);
  sort(all(arr));
  int x = (k - 1) / 2;
  multiset <int> left, right;
  ll sum_left = 0;
  ll sum_right = 0;
  for (int i = 0; i < x; i++) left.insert(arr[i]), sum_left += arr[i];
  for (int i = x; i < k; i++) right.insert(arr[i]), sum_right += arr[i];
  auto get = [&] () {
    ll m = *begin(right);
    return (sz(left) * m - sum_left) + (sum_right - sz(right) * m);
  };
  vll ans = {get()};
  for (int i = k; i < n; i++) {
    if (a[i] < *begin(right)) left.insert(a[i]), sum_left += a[i];
    else right.insert(a[i]), sum_right += a[i];
    if (left.count(a[i - k])) left.erase(left.find(a[i - k])), sum_left -= a[i - k];
    else right.erase(right.find(a[i - k])), sum_right -= a[i - k];
    while (sz(left) < x) {
      left.insert(*begin(right));
      sum_left += *begin(right);
      sum_right -= *begin(right);
      right.erase(begin(right));
    }
    while (sz(left) > x) {
      right.insert(*rbegin(left));
      sum_right += *rbegin(left);
      sum_left -= *rbegin(left);
      left.erase(--end(left));
    }
    ans.pb(get());
  }
  for (int i = 0; i < sz(ans); i++) cout << ans[i] << " \n"[i == sz(ans) - 1];
  return (0);
}
