#include <bits/stdc++.h>

using namespace std;

int n, k, aux, d;
long long ans, tmp;
vector <int> coef;

void f(int x){
   for(int i = 0; i < coef.size(); i++)
      ans += coef[i] * pow(x,i);
}

int main(){
   int c;
   scanf("%d", &c);
   while(c--){
      scanf("%d", &n);
      for(int i = 0; i <= n; i++)
         scanf("%d", &aux), coef.push_back(aux);
      scanf("%d", &d);
      scanf("%d", &k);
      tmp = 0;
      ans = 0;
      for(int i = 1; ; i++){
      tmp += i * d;
         if(tmp >= k){
            ans = 0;
            f(i);
            break;
         }
      }  
      cout << ans << endl;
      coef.clear();
   }
   return(0);
}
