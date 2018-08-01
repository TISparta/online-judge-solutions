#include <bits/stdc++.h>

#define SIZE 70

using namespace std;

int tc,n,back;
unsigned long long memo[SIZE][SIZE];

unsigned long long trib(int n,int back){
	unsigned long long sum = 0;
	if(n<=1) return 0;
	if(~memo[n][back]) return memo[n][back];
	for(int i=1;i<=back;i++)
		sum += 1+trib(n-i,back);
	return memo[n][back] = sum;
}

int main(){
	memset(memo,-1,sizeof memo);
	while(scanf("%d %d",&n,&back),n<=60)
		printf("Case %d: %llu\n",++tc,trib(n,back)+1);
	return(0);
}
