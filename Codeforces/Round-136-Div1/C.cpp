// Tags: Implementation
// Difficulty: 6.0
// Priority: 4
// Date: 19-08-2021

#include <bits/stdc++.h>
     
#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple

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
  vi w1(n + 1);
  for (int i = 0; i < n; i++) {
    int ai;
    cin >> ai;
    w1[ai] = i;
  }
  vi w2(n + 1);
  vi b(n);
  for (int i = 0; i < n; i++) {
    int bi;
    cin >> bi;
    b[i] = bi;
    w2[bi] = i;
  }
  set <pii> stl;
  set <pii> str;
  for (int i = 1; i <= n; i++) {
    if (w1[i] <= w2[i]) {
      str.emplace(w2[i] - w1[i], i);
    } else {
      stl.emplace(w1[i] - w2[i], i);
    }
  }
  for (int i = 0; i < n; i++) {
    int ans = n;
    if (not empty(stl)) {
      ans = min(ans, begin(stl)->first + i);
    }
    if (not empty(str)) {
      ans = min(ans, abs(begin(str)->first - i));
      auto it = str.lower_bound(pii(i, -1));
      if (it != end(str)) {
        ans = min(ans, abs(it->first - i));
      }
      if (it != begin(str)) {
        --it;
        ans = min(ans, abs(it->first - i));
      }
    }
    stl.erase(pii(abs(w1[b[i]] - w2[b[i]]), b[i]));
    str.erase(pii(abs(w1[b[i]] - w2[b[i]]), b[i]));
    str.emplace(n - 1 - w1[b[i]] + i + 1, b[i]);
    cout << ans << '\n';
  }
  return (0);
}
