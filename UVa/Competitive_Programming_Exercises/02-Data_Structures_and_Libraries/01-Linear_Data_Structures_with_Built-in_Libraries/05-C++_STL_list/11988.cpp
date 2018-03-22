#include <bits/stdc++.h>

#define SIZE 100010

using namespace std;

char s[SIZE];
list <char> v;
bool _home;
list <char> ::iterator it;

int main(){
   while(scanf("%s", s) != EOF){
      v.clear(), _home = false;
      for(int i = 0; s[i]; i++)
         if(s[i] == '[') _home = true, it = v.begin();
         else if(s[i] == ']') _home = false;
         else if(_home) v.insert(it, s[i]);
         else v.push_back(s[i]);
      for(it = v.begin(); it != v.end(); ++it) printf("%c", *it);
      putchar('\n');
   }
   return(0);
}
