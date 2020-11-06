// Implementation
// 2
// 06-11-2020

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
  vi a(n);
  vi ans;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    int j = i;
    while (j + 1 < n and a[j] < a[j + 1]) j += 1;
    ans.pb(a[j]);
    i = j;
  }
  cout << sz(ans) << '\n';
  for (int i = 0; i < sz(ans); i++) cout << ans[i] << " \n"[i == sz(ans) - 1];
  return (0);
}
