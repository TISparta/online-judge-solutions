// Brute Force
// 1.5
// 30-04-2021

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
  string s;
  cin >> n >> s;
  int a = count(all(s), 'A');
  int f = count(all(s), 'F');
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'F') continue;
    int add = (s[i] == 'I');
    if (add + a + f == n) ans += 1;
  }
  cout << ans << '\n';
  return (0);
}
