// Constructive Algorithms
// 4
// 08-12-2020

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
  int m, k;
  cin >> m >> k;
  int n = 1 << m;
  if (k >= n) {
    cout << -1 << '\n';
    return (0);
  }
  if (k == 0) {
    for (int i = 0; i < n; i++) {
      cout << i << ' ' << i << " \n"[i == n - 1];
    }
    return (0);
  }
  deque <int> a = {k};
  for (int i = 0; i < n; i++) {
    if (i == k) continue;
    a.push_front(i);
    a.push_back(i);
  }
  int x = 0;
  for (int ai: a) {
    if (ai == k) break;
    x ^= ai;
  }
  if (x != k) {
    cout << -1 << '\n';
    return (0);
  }
  a.push_front(k);
  for (int i = 0; i < 2 * n; i++) {
    cout << a[i] << " \n"[i == 2 * n - 1];
  }
  return (0);
}
