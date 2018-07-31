#include <bits/stdc++.h>

#define MAX_N 10
#define MAX_W 7500

using namespace std;

int n,v[]={1,5,10,25,50},memo[MAX_N][MAX_W];

int ways(int id,int sum){
	if(id==5 || sum<0) return 0;
	if(sum==0) return 1;
	if(~memo[id][sum]) return memo[id][sum];
	return memo[id][sum] = ways(id+1,sum)+ways(id,sum-v[id]);

}

int main(){
	memset(memo,-1,sizeof memo);
	while(scanf("%d",&n)==1)
		printf("%d\n",ways(0,n));
	return(0);
}
