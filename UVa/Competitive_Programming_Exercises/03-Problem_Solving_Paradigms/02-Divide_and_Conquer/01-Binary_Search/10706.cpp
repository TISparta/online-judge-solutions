#include <bits/stdc++.h>

#define LIM 31500

using namespace std;

int tc, n, tmp, aux, l, d = 1;
vector <long> sum;
string ans;

int main(){
   sum.push_back(0);
   for(int i = 1; i < LIM; i++){
      if(!(i % 10) && i / (int)pow(10, d) == 1) d++;
      tmp += d;
      sum.push_back(sum[i - 1] + tmp);
   }
   for(int i = 1; i <= tmp; i++){
      aux = i;
      l = 0;
      while(aux) l++, aux /= 10;
      aux = i;
      while(l)
         ans.push_back(aux / (int)pow(10, l - 1) + 48), aux %= (int)pow(10, l - 1), l--;   
   }
   scanf("%d", &tc);  
   while(tc--){
      scanf("%d", &n);
      printf("%c\n", ans[n - 1 - sum[lower_bound(sum.begin(), sum.end(), n) - sum.begin() - 1]]);
   }
   return(0);
}
