#include <bits/stdc++.h>

using namespace std;

string s, ss;
set <string> v;

int main(){
   while(getline(cin, s)){
      for(int i = 0; i < s.size(); i++){
         if(isalpha(s[i]) || s[i] == '-'){
            while(i < s.size() && (isalpha(s[i]) || s[i] == '-') )
               if(i == s.size() - 1 && s[i] == '-') goto jump;
               else ss += tolower(s[i]), i++;      
         }
         if(!ss.empty()) v.insert(ss), ss = "";
         jump: ;
      }        
   }
   for(set <string> ::iterator it = v.begin(); it != v.end(); ++it)
      printf("%s\n", (*it).c_str());
   return(0);
}
