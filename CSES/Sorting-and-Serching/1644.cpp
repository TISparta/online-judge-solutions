// Brute Force
// 4
// 12-09-2020

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
  int n, a, b;
  cin >> n >> a >> b;
  vll x(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
    x[i] += x[i - 1];
  }
  ll ans = LLONG_MIN;
  multiset <ll> frec;
  frec.insert(0);
  for (int i = a; i <= n; i++) {
    ans = max(ans, x[i] - *begin(frec));
    if (i >= b) frec.erase(frec.find(x[i - b]));
    frec.insert(x[i - a + 1]);
  }
  // a = 2
  // b = 4
  //
  // a0 a1 a2 a3 a4 a5 a6 a7 a8 a9 a10
  // 5-> a3, a2, a1
  // 6-> a4, a3, a2
  // 7-> a5, a4, a3
  cout << ans << '\n';
  return (0);
}
