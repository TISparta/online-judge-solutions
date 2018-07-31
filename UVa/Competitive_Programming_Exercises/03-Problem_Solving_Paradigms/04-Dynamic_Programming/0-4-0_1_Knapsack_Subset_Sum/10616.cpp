#include <bits/stdc++.h>

#define MAX_N 210
#define MAX_M 20
#define MAX_SUM 30

using namespace std;

int n,q,v[MAX_N],tc,d,m,memo[MAX_N][MAX_M][MAX_SUM];

int dp(int it,int ct,long long sum){
	if(ct==0 && sum==0) return 1;
	if(ct==0 && sum!=0) return 0;
	if(it==0) return 0;
	if(memo[it][ct][sum]!=-1) return memo[it][ct][sum];
	return memo[it][ct][sum] = dp(it-1,ct,sum)+dp(it-1,ct-1,(d+(sum+v[it])%d)%d);
}

int main(){
	while(scanf("%d %d",&n,&q),n|q){
		for(int i=1;i<=n;i++) scanf("%d",&v[i]);
		printf("SET %d:\n",++tc);
		for(int t=1;t<=q;t++){
			memset(memo,-1,sizeof memo);
			scanf("%d %d",&d,&m);
			printf("QUERY %d: %d\n",t,dp(n,m,0));
		}
	}
	return(0);
}
