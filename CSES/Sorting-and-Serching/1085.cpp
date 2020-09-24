// Binary Search
// 3
// 10-09-2020

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
  int n, k;
  cin >> n >> k;
  vi x(n);
  for (int& xi: x) cin >> xi;
  ll l = *max_element(all(x)), r = 1e15;
  while (l != r) {
    ll m = (l + r) >> 1;
    ll need = 0;
    for (int l = 0; l < n; l++) {
      ll sum = x[l];
      int r = l;
      while (r + 1 < n and sum + x[r + 1] <= m) r += 1, sum += x[r];
      need += 1;
      l = r;
    }
    if (need <= k) r = m;
    else l = m + 1;
  }
  cout << l << '\n';
  return (0);
}
