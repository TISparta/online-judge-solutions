// Greedy
// 2
// 25-11-2020

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
  vi a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  int cnt = 0;
  for (int i = 2; i < n; i++) {
    if (a[i] == 0 and a[i - 1] + a[i + 1] == 2) {
      cnt += 1;
      a[i + 1] = 0;
    }
  }
  cout << cnt << '\n';
  return (0);
}
