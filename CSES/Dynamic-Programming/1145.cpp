// DP
// 3
// 13-09-2020

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
  vi x(n);
  for (int& xi: x) cin >> xi;
  vi lis = {x[0]};
  for (int i = 1; i < n; i++) {
    if (x[i] < lis[0]) {
      lis[0] = x[i];
    } else if (lis.back() < x[i]) {
      lis.pb(x[i]);
    } else {
      int pos = lower_bound(all(lis), x[i]) - begin(lis);
      lis[pos] = x[i];
    }
  }
  cout << sz(lis) << '\n';
  return (0);
}
