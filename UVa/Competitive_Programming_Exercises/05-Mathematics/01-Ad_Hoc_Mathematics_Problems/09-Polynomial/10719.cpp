#include <bits/stdc++.h>

using namespace std;

const int SIZE = 10010;

long long k, a[SIZE], n, taken;
string line;

int main(){
   while(scanf("%lld\n", &k) != EOF){
      getline(cin, line);
      istringstream s(line);
      n = 0;
      while( s >> taken ) a[n++] = taken;
      for(int it = 1; it < n; it++)
         a[it] += a[it - 1] * k;
      printf("q(x):");
      for(int it = 0; it + 1 < n; it++)
         printf(" %lld", a[it]);
      putchar('\n');
      printf("r = %lld\n\n", a[n - 1]);
   }
   return(0);
}
