// Implementation
// 2
// 31-10-2020

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
  string s1, s2, s3;
  cin >> s1 >> s2 >> s3;
  auto process = [&] (string s) {
    string ret = "";
    for (char ch: s) {
      if (ch == '-' or ch == '_' or ch == ';') continue;
      ret += tolower(ch);
    }
    return ret;
  };
  s1 = process(s1);
  s2 = process(s2);
  s3 = process(s3);
  vector <string> valid = {
    s1 + s2 + s3,
    s1 + s3 + s2,
    s2 + s1 + s3,
    s2 + s3 + s1,
    s3 + s2 + s1,
    s3 + s1 + s2
  };
  int tt;
  cin >> tt;
  while (tt--) {
    string x;
    cin >> x;
    x = process(x);
    if (find(all(valid), x) != end(valid)) cout << "ACC\n";
    else cout << "WA\n";
  }
  return (0);
}
