#include <bits/stdc++.h>

#define SIZE 60

using namespace std;

int N,K,M;
unsigned long long memo[SIZE][SIZE][SIZE];

unsigned long long dp(int n,int k,int m){
	if(k==0 && n==0) return 1;
	if(k==0) return 0;
	if(n<=0) return 0;
	if(~memo[n][k][m]) return memo[n][k][m];
	unsigned long long ans = 0;
	for(int it=1;it<=m;it++)
		ans += dp(n-it,k-1,m);
	return memo[n][k][m] = ans;
}

int main(){
	memset(memo,-1,sizeof memo);
	while(scanf("%d %d %d",&N,&K,&M)==3)
		printf("%lld\n",dp(N,K,M));
	return(0);
}
