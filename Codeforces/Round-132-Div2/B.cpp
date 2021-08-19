// Tags: Math
// Difficulty: 2.0
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
  vi x(n);
  for (int& xi: x) cin >> xi;
  int m;
  cin >> m;
  vi y(m);
  for (int& yi: y) cin >> yi;
  int k;
  cin >> k;
  vi z(k);
  for (int& zi: z) cin >> zi;
  int A, B;
  cin >> A >> B;
  double r2 = 0;
  int r1 = *max_element(all(x));
  for (int p1: y) {
    for (int p2: z) {
      double r2_t = r1 * sqrt(1.0 * (p1 * B) / (p1 * B + p2 * A));
      if (r2_t < r1) r2 = max(r2, r2_t);
    }
  }
  cout << fixed << setprecision(12) << r2 << '\n';
  return (0);
}
