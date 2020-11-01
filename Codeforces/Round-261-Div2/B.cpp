// Implementation
// 2
// 20-01-2016

#include <stdio.h>
#include <string.h>

int main(){
	int n,a[200000],i,min,max;
	double num_min, num_max, ans;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	min = 2000000000;
	max = 0;
	for(i=0;i<n;i++){
		if(a[i]>max)
			max = a[i];
		if(a[i]<min)
			min = a[i];
	}
	num_min = num_max = 0;
	for(i=0;i<n;i++){
		if(a[i]==max)
			num_max+=1;
		if(a[i]==min)
			num_min+=1;
	}
	if(max!=min) ans=num_max*num_min;
	else ans = (num_max-1)*(num_max)/2;
	printf("%d %.0f\n",max-min,ans);
	return(0);
}
