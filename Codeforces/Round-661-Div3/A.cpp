// Ad-Hoc
// 2
// 05-08-2020

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
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vi arr(n);
    for (int& x: arr) cin >> x;
    sort(all(arr));
    bool ok = true;
    for (int i = 1; i < n; i++) ok &= (arr[i] - arr[i - 1] <= 1);
    if (ok) cout << "YES\n";
    else cout << "NO\n";
  }
  return (0);
}
