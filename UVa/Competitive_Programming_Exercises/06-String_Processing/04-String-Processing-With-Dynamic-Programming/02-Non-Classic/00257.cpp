#include <bits/stdc++.h>

using namespace std;

string s;

bool isPalindrome (const string s) {
  string rs = s;
  reverse(begin(rs), end(rs));
  return s == rs;
}

bool contains (string x, string y) {
  if (x.size() > y.size()) swap(x, y);
  if (x.size() == 3) {
    if (y.size() == 3) return x == y;
    return y.substr(0, 3) == x or y.substr(1, 3) == x;
  }
  return y == x or y.substr(0, 3) == x.substr(0, 3) or
    y.substr(0, 3) == x.substr(1, 3) or
    y.substr(1, 3) == x.substr(0, 3) or
    y.substr(1, 3) == x.substr(1, 3);
}

bool isPalinword () {
  set <string> st;
  for (int i = 0; i < s.size(); i++)
    for (int j = i + 2; j <= i + 3 and j < s.size(); j++)
      if (isPalindrome(s.substr(i, j - i + 1)))
        st.insert(s.substr(i, j - i + 1));
  for (string x: st)
    for (string y: st)
      if (not contains(x, y)) return true;
  return false;
}

int main () {
  while (cin >> s) if (isPalinword()) cout << s << endl;
  return (0);
}
