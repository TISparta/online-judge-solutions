#include <bits/stdc++.h>

using namespace std;

int a[26][26];
bool b[26][26];
int ans1, ans2;
string s;

void f(int i, int j){
   if(!b[i][j] && !b[j][i]) ans1++;
   for(int x = 0; x < 26; x++)
      if( j != x && a[j][x] == 1 && !b[j][x]){
         b[j][x]=true;
         f(j, x);
      }
}

int main(){
   int c, aux1, aux2;
   scanf("%d", &c);
   while(c--){
      memset(a, 0, sizeof a);
      memset(b, false, sizeof b);
         while(cin>>s){
            if(s[0]!='*'){
               a[s[1]-'A'][s[3]-'A'] = 1;
               a[s[3]-'A'][s[1]-'A'] = 1;
               a[s[1]-'A'][s[1]-'A'] = 1;
               a[s[3]-'A'][s[3]-'A'] = 1;
            }
            else break;
         }
      cin >> s;
      aux2 = 0;
      aux1 = s.size() - s.size() / 2;
      for(int i = 0; i < 26; i++) if(a[i][i]) aux2++;
      ans2 = aux1 - aux2;
      ans1 = 0;
      for(int i = 0; i < 26; i++)
         for(int j = 0; j < 26; j++)
            if(i != j && a[i][j] == 1) f(i, j);
      printf("There are %d tree(s) and %d acorn(s).\n", ans1, ans2);
   }
   return(0);
}
