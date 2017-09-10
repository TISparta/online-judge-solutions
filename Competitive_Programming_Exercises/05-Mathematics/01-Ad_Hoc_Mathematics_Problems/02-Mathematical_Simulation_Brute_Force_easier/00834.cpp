#include <bits/stdc++.h>

using namespace std;

int main(){
   int n, m;
   vector <int> a;
   while(scanf("%d %d", &n, &m) == 2){
      while(m > 0){
         a.push_back(n / m);
         n %= m;
         swap(n, m);
      }
      putchar('[');
      for(int i = 0; i < a.size(); i++){
         printf("%d", a[i]);
         if(i == 0 && a.size() != 1)
            putchar(';');
         else if(i != a.size() - 1)
            putchar(',');
      }
      printf("]\n");
      a.clear();
   }
   return(0);
}
