#include <bits/stdc++.h>

#define MAX_N 50

using namespace std;

int tc,ans,v1[MAX_N],v2[MAX_N],m,mod;

void backtrack(int id,int sum1,int sum2,int ct){
	if(id==m || sum1*sum1+sum2*sum2>mod || ct>=ans) return;
	if(sum1*sum1+sum2*sum2==mod){
			ans = ct;
			return;
	}
	backtrack(id,sum1+v1[id],sum2+v2[id],ct+1);
	backtrack(id+1,sum1,sum2,ct);
}

int main(){
	scanf("%d",&tc);
	while(tc--){
		ans = INT_MAX;
		scanf("%d %d",&m,&mod);
		mod *= mod;
		for(int i=0;i<m;i++) scanf("%d %d",&v1[i],&v2[i]);
		backtrack(0,0,0,0);
		if(ans==INT_MAX) puts("not possible");
		else printf("%d\n",ans);
	}
	return(0);
}
