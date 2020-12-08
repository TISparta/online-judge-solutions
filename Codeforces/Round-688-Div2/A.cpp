// Implementation
// 1
// 04-12-2020

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
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    set <int> a;
    set <int> b;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a.emplace(x);
    }
    for (int i = 0; i < m; i++) {
      int x;
      cin >> x;
      b.emplace(x);
    }
    int ans = 0;
    for (int ai: a) {
      ans += b.count(ai);
    }
    cout << ans << '\n';
  }
  return (0);
}
