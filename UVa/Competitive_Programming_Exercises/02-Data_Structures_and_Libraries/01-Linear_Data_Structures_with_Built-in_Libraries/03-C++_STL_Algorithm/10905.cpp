#include <bits/stdc++.h>

#define SIZE 60

using namespace std;

int n;
string v[SIZE], s1, s2;

bool f(string x, string y){
   s1 = x + y, s2 = y + x;
   return (s1 > s2);
}

int main(){
   while(scanf("%d", &n), n!=0){
      for(int i = 0;i < n; i++) cin >> v[i];
      sort(v, v + n, f);
      for(int i = 0; i < n; i++) cout << v[i]; cout << endl;
   }
   return(0);
}
