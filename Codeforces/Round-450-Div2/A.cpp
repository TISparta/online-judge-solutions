// Implementation
// 1
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
  int left = 0;
  int right = 0;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    if (x < 0) left += 1;
    if (x > 0) right += 1;
  }
  if (left <= 1 or right <= 1) cout << "Yes\n";
  else cout << "No\n";
  return (0);
}
