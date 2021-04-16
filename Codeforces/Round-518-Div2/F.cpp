// Constructive Algorithms
// 5
// 16-05-2021

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
  for (int i = 0; i < n; i++) {
    int z = (i + 3) / 4;
    int m = i % 4;
    if (m == 0) cout << 0 << ' ' << z << '\n';
    if (m == 1) cout << z << ' ' << 0 << '\n';
    if (m == 2) cout << 0 << ' ' << -z << '\n';
    if (m == 3) cout << -z << ' ' << 0 << '\n';
  }
  return (0);
}
