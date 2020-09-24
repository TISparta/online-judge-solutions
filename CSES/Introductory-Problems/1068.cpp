// Ad-Hoc
// 1
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
  ll n;
  cin >> n;
  vll ans = {n};
  while (n != 1) {
    if (n % 2 == 0) n /= 2;
    else n = n * 3 + 1;
    ans.pb(n);
  }
  for (int i = 0; i < sz(ans); i++) {
    cout << ans[i] << " \n"[i == sz(ans) - 1];
  }
  return (0);
}
