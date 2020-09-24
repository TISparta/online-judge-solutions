// Implementation
// 2
// 03-09-2020

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
  vll a(n);
  for (auto& ai: a) cin >> ai;
  ll ans = 0;
  for (int i = 1; i < n; i++) {
    ans += max(0LL, a[i - 1] - a[i]);
    a[i] = max(a[i], a[i - 1]);
  }
  cout << ans << '\n';
  return (0);
}
