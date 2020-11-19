// Math
// 1
// 14-09-2018

#include <bits/stdc++.h>

using namespace std;

int a, b;

int main(){
   scanf("%d %d", &a, &b);
   puts( ( abs(a - b) <= 1 ) and ( a + b ) ? "YES" : "NO" );
   return(0);
}
