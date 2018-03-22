#include <bits/stdc++.h>

using namespace std;

int tc, B, SG, SB, num, a, b, ct;
multiset <int, greater <int> > ::iterator it;

int main(){
   scanf("%d", &tc);
   while(tc--){
      multiset <int, greater <int> > green, blue;
      scanf("%d %d %d", &B, &SG, &SB);
      for(int i = 0; i < SG; i++) scanf("%d", &num), green.insert(num);
      for(int i = 0; i < SB; i++) scanf("%d", &num), blue.insert(num);
      while(!green.empty() && !blue.empty()){
         vector <int> next_green, next_blue;
         ct = 0;
         for(it = green.begin(); it != green.end() && ct != B && !blue.empty(); ++it, ct++){
            a = *it, b = *blue.begin();
            if(a > b) next_green.push_back(a - b);
            else if(a < b) next_blue.push_back(b - a);
            blue.erase(blue.begin());
         }
         while(ct--) green.erase(green.begin());
         for(int i = 0; i < next_green.size(); i++) green.insert(next_green[i]);
         for(int i = 0; i < next_blue.size(); i++) blue.insert(next_blue[i]);
      }
      if(!green.empty() && blue.empty()){
         puts("green wins");
         for(it = green.begin(); it != green.end(); ++it) printf("%d\n", *it);
      }
      else if(green.empty() && !blue.empty()){
         puts("blue wins");
         for(it = blue.begin(); it != blue.end(); ++it) printf("%d\n", *it);
      }
      else puts("green and blue died");
      if(tc) putchar('\n');
   }
   return(0);
}
