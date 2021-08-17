// Tags: Implementation
// Difficulty: 3.3
// Priority: 4
// Date: 17-08-2021

#include <bits/stdc++.h>
     
#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple

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
  map <string, string> parent;
  string pwd = "";
  while (n--) {
    string s;
    cin >> s;
    if (s == "pwd") {
      cout << pwd << "/\n";
      continue;
    }
    string command;
    cin >> command;
    stringstream ss(command);
    vector <string> arr;
    string z;
    while (getline(ss, z, '/')) arr.pb(z);
    // Absolute
    if (empty(arr[0])) {
      arr.erase(begin(arr));
      string cur = "";
      for (auto si: arr) {
        if (si == "..") {
          cur = parent[cur];
        } else {
          string nxt = cur + "/" + si;
          parent[nxt] = cur;
          cur = nxt;
        }
      }
      pwd = cur;
    } else { // Relative
      string cur = pwd;
      for (auto si: arr) {
        if (si == "..") {
          cur = parent[cur];
        } else {
          string nxt = cur + "/" + si;
          parent[nxt] = cur;
          cur = nxt;
        }
      }
      pwd = cur;
    }
  }
  return (0);
}
