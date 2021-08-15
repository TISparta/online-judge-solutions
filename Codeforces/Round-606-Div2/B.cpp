// Tags: Greedy
// Difficulty: 1.5
// Priority: 4
// Date: 14-04-2021

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
    int n;
    cin >> n;
    set <int> z;
    for (int i = 0; i < n; i++) {
      int ai;
      cin >> ai;
      if (ai & 1) continue;
      z.emplace(ai);
    }
    int ans = 0;
    while (not z.empty()) {
      ans += 1;
      int ai = *rbegin(z);
      z.erase(--end(z));
      ai >>= 1;
      if (ai % 2 == 0) {
        z.emplace(ai);
      }
    }
    cout << ans << '\n';
  }
  return (0);
}
