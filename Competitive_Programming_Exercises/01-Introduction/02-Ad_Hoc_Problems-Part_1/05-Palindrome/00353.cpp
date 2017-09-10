#include <bits/stdc++.h>

using namespace std;

string s;
int ans;
set <string> vis;

void check(string x){
   if( vis.find(x) == vis.end() ){
      for(int i = 0, j = x.size() - 1; i < j; i++, j--)
         if(x[i] != x[j]) return;
      ans++;
      vis.insert(x);
   }
}

int main(){
   while(cin >> s){
      vis.clear();
      ans = 0;
      for(int i = 0; i < s.size(); i++)
         for(int j = 0; j < s.size() - i; j++)
            check(s.substr(i, j + 1));
      printf("The string '%s' contains %d palindromes.\n", s.c_str(), ans);
   }
   return(0);
}
