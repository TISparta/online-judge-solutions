// Implementation
// 1
// 08-12-2020

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
  int x = (s[0] - '0') * 10 + (s[1] - '0');
  int y = (s[2] - '0') * 10 + (s[3] - '0');
  int flag1 = 0;
  int flag2 = 0;
  if (1 <= y and y <= 12) flag1 = 1;
  if (1 <= x and x <= 12) flag2 = 1;
  if (flag1 == 1 and flag2 == 0) cout << "YYMM\n";
  if (flag1 == 0 and flag2 == 1) cout << "MMYY\n";
  if (flag1 == 1 and flag2 == 1) cout << "AMBIGUOUS\n";
  if (flag1 == 0 and flag2 == 0) cout << "NA\n";
  return (0);
}
