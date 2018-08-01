#include <bits/stdc++.h>

#define MAX_N 110
#define MAX_K 110
const int MOD = 1000000;
int N,K,memo[MAX_N][MAX_K];

using namespace std;

int ways(int n,int k){
	if(k==1) return 1;
	if(~memo[n][k]) return memo[n][k];
	int ans = 0;
	for(int it=0;it<=n;it++)
		ans = (ans+ways(n-it,k-1))%MOD;
	return memo[n][k] = ans;
}

int main(){
	memset(memo,-1,sizeof memo);
	while(scanf("%d %d",&N,&K),N|K) printf("%d\n",ways(N,K));
	return(0);
}
