#include <bits/stdc++.h>

#define LIM (int)1e6

using namespace std;

int n, m, a, b, c;
bitset <1000010> bs;

bool ok;

int main(){
   while(scanf("%d %d",&n, &m),n | m){
      ok = true, bs.reset();
      for(int i = 0; i < n; i++){
         scanf("%d %d", &a, &b);
         for(int it = a; it < b; it++){
            if(bs.test(it)) ok = false;
            bs.set(it, 1);
         }
      }
      for(int i = 0; i < m; i++){
         scanf("%d %d %d", &a, &b, &c);
         int it = a;
         while(it <= LIM){
            if(bs.test(it)) ok = false;
            bs.set(it, 1);
            it++;
            if(it == b) a += c, b += c, it = a;
         }
      }
      puts( ok ? "NO CONFLICT" : "CONFLICT" );
   }
   return(0);
}
