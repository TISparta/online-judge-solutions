// Math
// 4
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
  int q;
  cin >> q;
  multiset <ll> left;
  multiset <ll> right;
  ll sum_b = 0;
  ll sum_left = 0;
  ll sum_right = 0;
  for (int i = 0; i < q; i++) {
    int type;
    cin >> type;
    if (type == 1) {
      ll a, b;
      cin >> a >> b;
      sum_b += b;
      left.emplace(a);
      sum_left += a;
      int len = (sz(left) + sz(right) + 1) / 2;
      if (sz(left) > len) {
        auto it = --end(left);
        sum_left -= *it;
        sum_right += *it;
        right.emplace(*it);
        left.erase(it);
      }
      while (sz(right) and *rbegin(left) > *begin(right)) {
        auto x = *(--end(left));
        int y = *begin(right);
        sum_left = sum_left - x + y;
        sum_right = sum_right - y + x;
        left.erase(--end(left));
        right.erase(begin(right));
        left.emplace(y);
        right.emplace(x);
      }
    } else {
      ll x = *(--end(left));
      ll fx = sz(left) * x - sum_left + sum_right - sz(right) * x + sum_b;
      cout << x << ' ' << fx << '\n';
    }
  }
  return (0);
}
