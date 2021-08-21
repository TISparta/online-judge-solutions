// Tags: Greedy
// Difficulty: 3.5
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
  int mx = 0, id = -1;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    frec[arr[i]]++;
    if (frec[arr[i]] > mx) {
      mx = frec[arr[i]];
      id = i;
    }
  }
  vector <pair <int, pair <int, int>>> go;
  for (int i = id - 1; i >= 0; i--) {
    if (arr[i] < arr[i + 1]) {
      go.push_back({1, {i, i + 1}});
    } else if (arr[i] > arr[i + 1]) {
      go.push_back({2, {i, i + 1}});
    }
    arr[i] = arr[i + 1];
  }
  for (int i = id + 1; i < n; i++) {
    if (arr[i] < arr[i - 1]) {
      go.push_back({1, {i, i - 1}});
    } else if (arr[i] > arr[i - 1]) {
      go.push_back({2, {i, i - 1}});
    }
    arr[i] = arr[i - 1];
  }
  cout << sz(go) << endl;
  for (auto pp: go) {
    cout << pp.first << ' ' << pp.second.first + 1 << ' ' << pp.second.second + 1 << '\n';
  }
  return (0);
}
