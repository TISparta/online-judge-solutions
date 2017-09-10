#include <bits/stdc++.h>

using namespace std;

int tc;
string s;
vector <string> ans;

bool cmp(const string x, const string y){
   for(int it = 0; it < x.size(); it++){
      if( x[it] == y[it] ) continue;
      if( tolower(x[it]) != tolower(y[it]) )
         return (tolower(x[it]) < tolower(y[it]));
      else
         return (x[it] < y[it]);
   }     
}

int main(){
   scanf("%d", &tc);
   while(tc--){
      ans.clear();
      cin >> s;
      sort(s.begin(), s.end());
      do{
         ans.push_back(s);
      }while(next_permutation(s.begin(), s.end()));
      sort(ans.begin(), ans.end(), cmp);
      for(int it = 0; it < ans.size(); it++)
         printf("%s\n", ans[it].c_str());
   }
   return(0);
}
