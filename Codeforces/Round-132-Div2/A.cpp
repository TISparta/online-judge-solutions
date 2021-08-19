// Tags: Brute Force
// Difficulty: 1.3
// Priority: 5
// Date: 17-08-2020

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
  for (int& x: a) cin >> x;
  int m;
  cin >> m;
  vi b(m);
  for (int& x: b) cin >> x;
  map <int, int> ans;
  for (int ai: a) for (int bi: b) if (bi % ai == 0) ans[-bi/ai]++;
  for (auto pp: ans) {
    cout << pp.second << '\n';
    break;
  }
  return (0);
}
