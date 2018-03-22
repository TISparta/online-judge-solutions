#include <bits/stdc++.h>

using namespace std;

string a[105], x, b;
int c, k, t;

void f(string b, int p, string x){
   if(p == b.size()){
      cout << x << endl;
      return;
   }
   if(b[p] == '0'){
      for(int i = 48; i < 58; i++){
         x.push_back(i);
         f(b,p + 1,x);
         x.pop_back();
      }           
   }
   else{
      for(int i = 0; i < c; i++){
         for(int j = 0; j < a[i].size(); j++)
            x.push_back(a[i][j]);
         f(b, p + 1, x);
         for(int j = 0; j < a[i].size(); j++)
            x.pop_back();
      }
   }
}

int main(){
   while(scanf("%d", &c) == 1){
      for(int i = 0; i < c; i++)
         cin >> a[i];
      scanf("%d", &t);
      while(t--){
         cin >> b;
         k = 0;
         string x;
         printf("--\n");
         f(b, 0, x);
      }
   }
   return(0);
}
