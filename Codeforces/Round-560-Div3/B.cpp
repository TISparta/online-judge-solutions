// Implementation
// 2
// 03-12-2020

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
  multiset <int> a;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a.emplace(x);
  }
  int ans = 0;
  for (int k = 1; ; k++) {
    auto it = a.lower_bound(k);
    if (it == end(a)) break;
    ans += 1;
    a.erase(it);
  }
  cout << ans << '\n';
  return (0);
}
