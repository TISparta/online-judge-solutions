#include <bits/stdc++.h>

#define SIZE 100

using namespace std;

char s[SIZE];
vector <string> v, dic;
string ss;
int ct;

int main(){
   while(scanf("%s", s), strcmp(s, "XXXXXX") != 0)
      v.push_back(string(s));
   sort(v.begin(), v.end());
   for(int it1 = 0; it1 < v.size(); it1++){
      ss = v[it1];
      sort(ss.begin(), ss.end());
      dic.push_back(ss);
   }
   while(scanf("%s", s), strcmp(s, "XXXXXX") != 0){
      ct = 0, ss = s;
      sort(ss.begin(), ss.end());
      for(int it = 0; it < dic.size(); it++)
         if( ss == dic[it] )
            printf("%s\n", v[it].c_str()), ct++;
      if( ct == 0 ) puts("NOT A VALID WORD");
      puts("******");
   }
   return(0);
}
