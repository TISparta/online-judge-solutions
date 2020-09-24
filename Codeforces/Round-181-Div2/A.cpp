// Implementantion
// 2
// 03-08-2020

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
  vector <int> arr(n);
  vi zero;
  bool neg = false;
  bool pos = false;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] < 0 and not neg) {
      neg = true;
      cout << 1 << ' ' << arr[i] << '\n';
      continue;
    }
    zero.pb(arr[i]);
  }
  for (int i = 0; i < n - 1; i++) {
    if (zero[i] > 0 and not pos) {
      pos = true;
      cout << 1 << ' ' << zero[i] << '\n';
      zero.erase(begin(zero) + i);
      break;
    }
  }
  if (not pos) {
    cout << 2;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < sz(zero); j++) {
        if (zero[j] < 0) {
          cout << ' ' << zero[j];
          zero.erase(begin(zero) + j);
          break;
        }
      }
    }
    cout << '\n';
  }
  cout << sz(zero);
  for (int ai: zero) cout << ' ' << ai; cout << '\n';
  return (0);
}
