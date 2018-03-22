#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

ll N,tmp,a,lim;
int tc, used[10];
bool ok;

int main(){
   scanf("%d", &tc);
   while(tc--){
      scanf("%lld", &N);
      for(ll b = 1; b <= 9876543210; b++){
         a = b * N, ok = true;
         if(a > (ll)(1e10)) break;
         memset(used, 0, sizeof used), tmp = a;
         while(tmp) used[tmp % 10]++, tmp /= 10;
         for(int j = 0; j < 10; j++)
            if(used[j] > 1) ok = false;
         memset(used, 0, sizeof used), tmp = b;
         while(tmp) used[tmp % 10]++, tmp /= 10;
         for(int j = 0; j < 10; j++)
            if(used[j] > 1) ok = false;
         if(ok) printf("%lld / %lld = %lld\n", a, b, N);
      }
      if(tc) putchar('\n');
   }
   return(0);
}
