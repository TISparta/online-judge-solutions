#include <bits/stdc++.h>

#define MAX_N 30
#define MAX_W 10010

using namespace std;

int v[MAX_N],n;
long long memo[MAX_N][MAX_W];

long long ways(int id,int sum){
	if(id==22 || sum<0) return 0;
	if(sum==0) return 1;
	if(~memo[id][sum]) return memo[id][sum];
	return memo[id][sum] = ways(id+1,sum)+ways(id,sum-v[id]);
}

int main(){
	for(int i=1;i<22;i++) v[i] = i*i*i;
	memset(memo,-1,sizeof memo);
	while(scanf("%d",&n)==1)
		printf("%lld\n",ways(1,n));
	return(0);
}
