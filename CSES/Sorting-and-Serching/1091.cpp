// Implementation
// 2
// 06-09-2020

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
  multiset <int> h;
  while (n--) {
    int hi;
    cin >> hi;
    h.insert(hi);
  }
  while (m--) {
    int ti;
    cin >> ti;
    if (h.empty() or *begin(h) > ti) {
      cout << -1 << '\n';
    } else {
      auto it = --h.upper_bound(ti);
      cout << *it << '\n';
      h.erase(it);
    }
  }
  return (0);
}
