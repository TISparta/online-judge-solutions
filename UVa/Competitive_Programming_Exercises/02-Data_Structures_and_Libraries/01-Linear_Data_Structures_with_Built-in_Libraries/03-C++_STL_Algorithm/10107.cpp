#include <bits/stdc++.h>

using namespace std;

int tmp, pib;
vector <int> v;

int main(){
   while(scanf("%d", &tmp) == 1){
      v.push_back(tmp);          
      pib = v.size() >> 1;
      nth_element(v.begin(), v.begin() + pib, v.end());
      if(v.size() & 1) printf("%d\n",v[pib]);
      else{
         nth_element(v.begin(), v.begin() + pib - 1, v.end());
         printf("%d\n",(v[pib] + v[pib-1]) >> 1);
      }
   }
   return(0);
}
