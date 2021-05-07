// Tags: Implementation
// Difficulty: 1.6
// Priority: 4
// Date: 07-05-2021

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
  int k;
  cin >> k;
  // 9: 1
  // 8: 2
  int x = k / 2;
  int y = k % 2;
  if (x + y > 18) {
    cout << -1 << '\n';
  } else {
    cout << string(x, '8') + string(y, '9') << '\n';
  }
  return (0);
}
