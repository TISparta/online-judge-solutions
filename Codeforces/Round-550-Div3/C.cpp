// Tags: Sorting
// Difficulty: 3.0
// Priority: 4
// Date: 31-03-2019

#include <bits/stdc++.h>

#define all(A) begin(A), end(A)
#define sz(A) int(A.size())

using namespace std;

typedef long long ll;

const int MAX_VAL = 2e5 + 10;

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  vector <int> arr(n);
  vector <int> frec(MAX_VAL, 0);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    frec[arr[i]]++;
    if (frec[arr[i]] >= 3) {
      cout << "NO" << endl;
      return (0);
    }
  }
  cout << "YES" << endl;
  vector <int> inc, dec;
  sort(all(arr));
  inc.push_back(arr[0]);
  for (int i = 1; i < n; i++) {
    if (arr[i] != inc.back()) {
      inc.push_back(arr[i]);
    } else {
      dec.push_back(arr[i]);
    }
  }
  reverse(all(dec));
  cout << sz(inc) << endl;
  for (int elem: inc) cout << elem << ' '; cout << endl;
  cout << sz(dec) << endl;
  for (int elem: dec) cout << elem << ' '; cout << endl;
  return (0);
}
