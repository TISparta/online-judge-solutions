// Tags: Greedy
// Difficulty: 1.5
// Priority: 4
// Date: 10-02-2016

#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,c_1=0,c_2=0,c_3=0,ans=0;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]==1)
			c_1++;
		else if(a[i]==2)
			c_2++;
		else if(a[i]==3)
			c_3++;
		else
			ans++;
	}
	ans+=c_3;
	c_1-=c_3;
	ans+= c_2/2;
	c_2 %= 2;
	if(c_1>0){
		ans+=(c_1+c_2*2)/4;
	c_1=(c_1+c_2*2)%4;
	if(c_1>0 && c_1<4)
		ans++;
	}
	else if(c_2==1)
		ans++;
	cout<<ans<<endl;

}
