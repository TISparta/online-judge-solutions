#include <bits/stdc++.h>

using namespace std;

string solve () {
  string A;
  cin >> A;
  for (int it1 = 0; it1 < A.size(); it1++) {
    for (int it2 = it1 + 1; it2 < A.size(); it2++) {
      int it3 = it2;
      if (it3 + it1 >= A.size()) {
        it1 = A.size();
        break;
      }
      int id = 0;
      while (id <= it1 and A[it3] == A[id]) it3++, id++;
      if (id != it1 + 1) continue;
      string ans = "";
      for (int i = 0; i < it3; i++) ans += A[i];
      for (int i = it1 + 1; i < it3; i++) ans += A[i];
      for (int i = it3; i < A.size(); i++) ans += A[i];
      int i = it3, j = it3;
      while (i < A.size() and j < ans.size()) {
        if (A[i] != ans[j]) return ans;
        i++, j++;
      }
    }
  }
  return "Impossible";
}

int main () {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++)
    cout << "Case #" << t << ": " << solve() << endl;
  return (0);
}
