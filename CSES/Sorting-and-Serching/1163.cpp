// Greedy
// 3
// 09-09-2020

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
  int x, n;
  cin >> x >> n;
  vi p(n);
  set <int> pos = {0, x};
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    pos.insert(p[i]);
  }
  vi ans(n);
  int last = 0;
  for (auto val: pos) {
    ans.back() = max(ans.back(), val - last);
    last = val;
  }
  for (int i = n - 1; i > 0; i--) {
    auto it = pos.upper_bound(p[i]);
    int x = *it;
    it--;
    it--;
    int y = *it;
    ans[i - 1] = max(x - y, ans[i]);
    it++;
    pos.erase(it);
  }
  for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n - 1];
  return (0);
}
