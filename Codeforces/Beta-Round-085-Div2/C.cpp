// Tags: Math
// Difficulty: 3.2
// Difficulty: 3
// Date: 16-08-2021

#include <bits/stdc++.h>
     
#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple

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
  ll n, x, y;
  cin >> n >> x >> y;
  if (y < n) {
    cout << -1 << '\n';
    return (0);
  }
  vll a(n, 1);
  a[0] = y - (n - 1);
  ll sum = 0;
  for (auto ai: a) sum += ai * ai;
  if (sum < x) {
    cout << -1 << '\n';
  } else {
    for (int i = 0; i < n; i++) cout << a[i] << " \n"[i + 1 == n];
  }
  return (0);
}
