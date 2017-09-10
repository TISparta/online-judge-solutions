#include <bits/stdc++.h>

using namespace std;

int n;
vector <long> trib;

int main(){
   trib.push_back(0), trib.push_back(0), trib.push_back(1);
   for(int i = 3; i <= 33; i++)
      trib.push_back(trib[i - 1] + trib[i - 2] + trib[i - 3]);
   while(scanf("%d", &n), n)
      printf("%ld\n",(1l << n) - trib[n + 3]);
   return(0);
}
