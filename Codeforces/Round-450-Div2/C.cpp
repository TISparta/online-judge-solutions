// Implementation
// 4
// 27-11-2020

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
  set <int> total;
  set <int> used;
  vi add(n + 1, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    auto it = used.upper_bound(a[i]);
    if (it == end(used)) {
      total.insert(a[i]);
    } else if (next(it) == end(used)) {
      add[*it] += 1;
    }
    used.emplace(a[i]);
  }
  pii ans(0, -n - 1);
  for (int i = 1; i <= n; i++) {
    int cost = sz(total) + add[i];
    if (total.count(i)) cost -= 1;
    ans = max(ans, pii(cost, -i));
  }
  cout << -ans.second << '\n';
  return (0);
}
