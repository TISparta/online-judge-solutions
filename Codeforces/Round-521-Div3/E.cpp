// Brute Force
// 4
// 24-11-2020

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
  map <int, int> frec;
  for (int i = 0; i < n; i++) {
    int ai;
    cin >> ai;
    frec[ai] += 1;
  }
  vi arr;
  for (auto [x, y]: frec) arr.pb(y);
  sort(all(arr));
  ll ans = 0;
  for (int i = 0; i < sz(arr); i++) {
    for (int x = 1; x <= arr[i]; x++) {
      ll sum = x;
      ll need = 2 * x;
      for (int j = i + 1; j < sz(arr) and arr[j] >= need; j++, need <<= 1) {
        sum += need;
      }
      ans = max(ans, sum);
    }
  }
  cout << ans << '\n';
  return (0);
}
