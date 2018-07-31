#include <bits/stdc++.h>

#define MAX_N 10 
#define MAX_W 30010

using namespace std;

int n,v[]={1,5,10,25,50};
long long ans,memo[MAX_N][MAX_W];

long long ways(int id,int sum){
	if(sum==0) return 1;
	if(sum<0 || id==5) return 0;
	if(~memo[id][sum]) return memo[id][sum];
	return memo[id][sum] = ways(id+1,sum)+ways(id,sum-v[id]);
}

int main(){
	memset(memo,-1,sizeof memo);
	while(scanf("%d",&n)==1){
		ans = ways(0,n);
		if(ans==1) printf("There is only 1 way to produce %d cents change.\n",n);
		else printf("There are %lld ways to produce %d cents change.\n",ans,n);
	}
	return(0);
}
