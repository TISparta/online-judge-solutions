#include <bits/stdc++.h>

using namespace std;

long n;

int main(){
   while(scanf("%ld", &n), n > 0)
      printf("%ld%%\n", n!=1 ? n * 25 : n * 0);
   return(0);
}
