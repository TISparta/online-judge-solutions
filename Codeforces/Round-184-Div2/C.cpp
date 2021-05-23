// Tags: Greedy
// Difficulty: 3.6
// Priority: 1
// Date: 22-05-2021

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
  map <ll, int> z;
  for (int i = 0; i < n; i++) {
    ll a;
    cin >> a;
    z[a] += 1;
  }
  ll cnt = 0;
  ll mx = 0;
  for (auto [key, value]: z) {
    if (value & 1) cnt += 1;
    if (value / 2) z[key + 1] += value / 2;
    mx = key;
  }
  cout << mx - cnt + 1 << '\n';
  return (0);
}
