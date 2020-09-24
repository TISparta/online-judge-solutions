// Ternary Search
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
  vi p(n);
  for (int& pi: p) cin >> pi;
  int l = 1, r = 1e9;
  auto f = [&] (int x) {
    ll ret = 0;
    for (auto pi: p) ret += abs(x - pi);
    return ret;
  };
  while (l != r) {
    int m = (l + r) >> 1;
    if (f(m) < f(m + 1)) r = m;
    else l = m + 1;
  }
  cout << f(l) << '\n';
  return (0);
}
