#include <bits/stdc++.h>

using namespace std;

int tc, n, tmp, price;
vector <int> v;
bool ok;

int main(){
   scanf("%d", &tc);
   while(tc--){
      v.clear(), ok = true;
      while(scanf("%d",&tmp), tmp) v.push_back(tmp);
      sort(v.rbegin(), v.rend());
      price = 0;
      for(int i = 0; i < v.size(); i++){
         price += 2 * pow(v[i], i + 1);
         if(price >= 5000000) ok = false, i = v.size();
      }
      if(ok) printf("%d\n", price);
      else puts("Too expensive");
   }

   return(0);
}
