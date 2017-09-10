#include <bits/stdc++.h>

using namespace std;

string s, ss;
set <string> v;

int main(){
   while(getline(cin, s)){
      for(int i = 0; i < s.size(); i++){
         ss = "";
         if(isalpha(s[i])){
            while(i < s.size() && isalpha(s[i])) ss += tolower(s[i]), i++;      
         }
         if(!ss.empty()) v.insert(ss);
      }           
   }
   for(set <string> ::iterator it = v.begin(); it != v.end(); ++it)
      printf("%s\n", (*it).c_str());
   return(0);
}
