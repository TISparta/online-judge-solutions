#include <bits/stdc++.h>

#define MAX_N 250
#define MAX_SUM 1500
#define MAX_K 20

using namespace std;

int sum,k,primes[MAX_N],n;
int dp[MAX_SUM][MAX_N][MAX_K];

bool p[MAX_SUM];

void sieve(){
	primes[n++] = 2;
	for(int i=3;i<MAX_SUM;i+=2)
		if(p[i]==false){
			for(int j=i+i;j<MAX_SUM;j+=i)
				p[j] = true;
			primes[n++] = i;
		}
}

int numberOfWays(int s,int it,int ct){
	if(s==0 && ct==0) return 1;
	if(s<=0 || it>=n || ct==0) return 0;
	if(dp[s][it][ct]!=-1) return dp[s][it][ct];
	return dp[s][it][ct] = numberOfWays(s-primes[it],it+1,ct-1)+numberOfWays(s,it+1,ct);
}

int main(){
	sieve();
	memset(dp,-1,sizeof dp);
	for(int it=0;it<MAX_N;it++)
		dp[0][it][0] = 1;
	while(scanf("%d %d",&sum,&k),sum|k)
		printf("%d\n",numberOfWays(sum,0,k));
	return(0);
}
