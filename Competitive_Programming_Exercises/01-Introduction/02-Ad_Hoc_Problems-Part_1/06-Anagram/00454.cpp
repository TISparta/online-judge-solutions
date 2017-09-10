#include <bits/stdc++.h>

using namespace std;

int tc;
string line;
vector <string> v, dic;

int main(){
   scanf("%d\n", &tc);
   while(tc--){
      v.clear();
      dic.clear();
      while(getline(cin, line)){
         if( line.empty() ) break;
         v.push_back(line);
      }
      sort(v.begin(), v.end());
      for(int it1 = 0; it1 < v.size(); it1++){
         string s = "";
         for(int it2 = 0; it2 < v[it1].size(); it2++)
            if( v[it1][it2] != ' ' )
               s += v[it1][it2];
         sort(s.begin(), s.end());
         dic.push_back(s);
      }
      for(int it1 = 0; it1 < v.size(); it1++)
         for(int it2 = it1 + 1; it2 < v.size(); it2++)
            if( dic[it1] == dic[it2] )
               printf("%s = %s\n", v[it1].c_str(), v[it2].c_str());
      if(tc) putchar('\n');
   }
   return(0);
}
