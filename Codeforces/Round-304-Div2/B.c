// Tags: Brute Force
// Difficulty: 1.7
// Priority: 3
// Date: 31-01-2016

#include <stdio.h>
#include <string.h>

int main(){
	int a[6001],i,j,ans=0,n,aux;
	scanf("%d",&n);
	memset(a,0,sizeof a);
	for(i=0;i<n;i++){
		scanf("%d",&aux);
		for(j=aux;j<=6000;j++){
			if(a[j]==0){
			a[j]=1;
			ans+=j-aux;
			break;
			}
		}
	}
	printf("%d\n",ans);
	return(0);
}
