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
  int n;
  cin >> n;
  int l = 0;
  map <int, int> pos;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int ai;
    cin >> ai;
    if (pos.count(ai)) {
      l = max(l, pos[ai]);
    }
    ans = max(ans, i - l);
    pos[ai] = i;
  }
  cout << ans << '\n';
  return (0);
}
