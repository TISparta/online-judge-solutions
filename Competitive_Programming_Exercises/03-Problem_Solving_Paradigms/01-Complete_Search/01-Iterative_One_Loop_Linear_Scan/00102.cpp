#include <bits/stdc++.h>
#define INF 2000000000

using namespace std;

int t , ans, aux, tmp;
int cases[] = {0, 2, 1, 0, 1, 2, 2, 0, 1, 2, 1, 0, 1, 0, 2, 1, 2, 0};
string s = "BGC", ss;
string ans_string;
int a[9];

int main(){
   while(scanf("%d", &a[t++]) == 1){
      if(t == 9){
         t = 0;
         aux = 0;
         ans = INF;
         for(int i = 0; i < 9; i++)
            aux += a[i];
         for(int i = 0; i < 18; i += 3){
            tmp = aux;
            ss.clear();
            for(int j = 0; j < 3; j++){
               ss += s[cases[i + j]];
               if(s[cases[i + j]] == 'B')
                  tmp -= a[j * 3 + 0];
               else if(s[cases[i + j]] == 'G')
                  tmp -= a[j * 3 + 1];
               else
                  tmp -= a[j * 3 + 2];
            }
         if(tmp < ans)
            ans = tmp, ans_string = ss;
         }
         cout << ans_string << ' ' << ans << endl;            
      }
   }
   return(0);
}
