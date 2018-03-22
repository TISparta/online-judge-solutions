#include <bits/stdc++.h>

using namespace std;

string a[1000];
char s[1000];
int ans[1000];
vector <int> aux;

int main(){
   int c, n, mini;
   scanf("%d", &c);
   while(c--){
      mini = 1000000;
      scanf("%d\n", &n);
      for(int i = 0; i < n; i++){
         getline(cin, a[i]);
         ans[i] = 1;
         for(int j = 0; j < a[i].size(); j++)
            if(a[i][j] == ' ') ans[i]++;
         mini = min(mini,ans[i]);
      }
      for(int i = 0; i < n; i++)
         if(ans[i] == mini) aux.push_back(i+1);
      for(int i = 0; i < aux.size(); i++){
         if(i) putchar(' ');
         cout<<aux[i];
      }
      putchar('\n');
      aux.clear();
   }
   return(0);
}
