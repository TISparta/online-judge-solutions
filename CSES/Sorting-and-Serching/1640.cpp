// Implementation
// 2
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
  int n, x;
  cin >> n >> x;
  map <int, vi> pos;
  for (int i = 1; i <= n; i++) {
    int ai;
    cin >> ai;
    pos[ai].pb(i);
  }
  for (auto pp: pos) {
    int a = pp.first;
    int b = x - a;
    if (a != b and pos.count(b)) {
      cout << pp.second.front() << ' ' << pos[b].front() << '\n';
      return (0);
    }
    if (a == b and sz(pp.second) > 1) {
      cout << pp.second[0] << ' ' << pp.second[1] << '\n';
      return (0);
    }
  }
  cout << "IMPOSSIBLE" << '\n';
  return (0);
}
