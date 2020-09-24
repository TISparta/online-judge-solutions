// Binary Search
// 3
// 05-09-2020

#include <bits/stdc++.h>
     
#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())
#define pb push_back
#define mp make_pair
     
using namespace std;
     
typedef __int128_t ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <pii> vpii;
typedef vector <pll> vpll;

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, t;
  cin >> n >> t;
  vi a(n);
  for (int& ai: a) cin >> ai;
  ll l = 1, r = 1e18;
  while (l != r) {
    ll m = (l + r) >> 1;
    ll have = 0;
    for (int ai: a) have += m / ai;
    if (have >= t) r = m;
    else l = m + 1;
  }
  cout << (long long)l << '\n';
  return (0);
}
