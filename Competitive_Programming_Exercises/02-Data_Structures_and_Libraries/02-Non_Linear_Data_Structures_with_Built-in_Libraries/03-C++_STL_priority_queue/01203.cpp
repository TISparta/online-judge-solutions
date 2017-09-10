#include <bits/stdc++.h>

#define SIZE 30

using namespace std;

int Q_num, Period, k;
char s[SIZE];
priority_queue < pair <int, int> > v;

int main(){
   while(cin.getline(s, SIZE)){
      if(sscanf(s,"%*s %d %d", &Q_num, &Period) == -1) break;
      for(int i = 0, it = Period; i < 10000; i++, it += Period)
         v.push(make_pair( -it, -Q_num));
   }
   scanf("%d",&k);
   while(k--){
      printf("%d\n", -v.top().second);
      v.pop();
   }
   return(0);
}
