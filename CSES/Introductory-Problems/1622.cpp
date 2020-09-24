// Implementation
// 1
// 04-09-2020

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
  string s;
  cin >> s;
  sort(all(s));
  vector <string> arr;
  do {
    arr.pb(s);
  } while (next_permutation(all(s)));
  cout << sz(arr) << '\n';
  for (auto si: arr) cout << si << '\n';
  return (0);
}
