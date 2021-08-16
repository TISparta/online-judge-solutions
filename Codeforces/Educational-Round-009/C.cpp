// Tags: Sorting
// Difficulty: 3.0
// Priority: 5
// Date: 09-06-2017

#include <bits/stdc++.h>

using namespace std;

int n;
vector <string> a;

bool cmp(string x, string y){
   string z1 = x + y;
   string z2 = y + x;
   return z1 < z2;
}

int main(){
   cin >> n;
   a.resize(n);
   for(int i = 0; i < n; i++) cin >> a[i];
   sort(a.begin(), a.end(), cmp);
   for(int i = 0; i < n; i++) cout << a[i]; cout << endl;
   return(0);
}
