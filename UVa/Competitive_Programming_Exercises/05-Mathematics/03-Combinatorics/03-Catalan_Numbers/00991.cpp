#include <bits/stdc++.h>

#define SIZE 20

using namespace std;

int tc,n,catalan[SIZE];

int main(){
	catalan[0] = 1;
	for(int it=1;it<12;it++)
		catalan[it] = catalan[it-1]*(4*it-2)/(it+1);
	while(~scanf("%d",&n)){
		if(tc++) putchar('\n');
		printf("%d\n",catalan[n]);
	}
	return(0);
}
