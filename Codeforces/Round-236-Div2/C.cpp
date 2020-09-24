// Greedy
// 3
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
  int tc;
  cin >> tc;
  while (tc--) {
    int n, p;
    cin >> n >> p;
    set <pii> edges;
    int target = 2 * n + p;
    for (int d = 1; d < n and sz(edges) != target; d++) {
      for (int i = 0; i < n and sz(edges) != target; i++) {
        int u = i;
        int v = (i + d) % n;
        if (u > v) swap(u, v);
        edges.insert(pii(u + 1, v + 1));
      }
    }
    for (auto pp: edges) cout << pp.first << ' ' << pp.second << '\n';
  }
  return (0);
}
