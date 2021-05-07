// Tags: Math
// Difficulty: 5.5
// Priority: 1
// Date: 04-05-2021

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
  ll p, k;
  cin >> p >> k;
  // find p in base (-k)
  k *= -1;
  vi ans;
  while (p != 0) {
    // p = q * k + r
    ll q = p / k;
    ll r = p - q * k;
    if (r < 0) {
      r += -k;
      q += 1;
    }
    ans.pb(r);
    p = q;
  }
  cout << sz(ans) << '\n';
  for (int i = 0; i < sz(ans); i++) cout << ans[i] << " \n"[i + 1 == sz(ans)];
  return (0);
}
